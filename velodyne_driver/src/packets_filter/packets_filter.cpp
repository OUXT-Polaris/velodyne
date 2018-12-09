#include <packets_filter/packets_filter.h>

packets_filter::packets_filter()
{

}

packets_filter::~packets_filter()
{

}

void packets_filter::init(ros::NodeHandle nh,ros::NodeHandle private_nh)
{
    nh_ = nh;
    private_nh.param<std::string>("input_topic",input_topic_,"velodyne_packets");
    double cut_start_angle_d,cut_end_angle_d;
    private_nh.param<double>("cut_start_angle",cut_start_angle_d,0);
    if(cut_start_angle_d < -1*M_PI || cut_start_angle_d > M_PI)
    {
        ROS_ERROR_STREAM("invalid value. cut_start_angle must be -1*PI to 1*Pi");
        cut_start_angle_d = 0;
    }
    if(cut_end_angle_d < -1*M_PI || cut_end_angle_d > M_PI)
    {
        ROS_ERROR_STREAM("invalid value. cut_end_angle must be -1*PI to 1*Pi");
        cut_end_angle_d = 0;
    }
    private_nh.param<double>("cut_end_angle",cut_end_angle_d,0);
    cut_start_angle_ = int(((cut_start_angle_d + M_PI)*360/(2*M_PI))*100);
    cut_end_angle_ = int(((cut_end_angle_d + M_PI)*360/(2*M_PI))*100);
    packets_pub_ = nh_.advertise<velodyne_msgs::VelodyneScan>("velodyne_packets/filtered", 10);
    packets_sub_ = nh_.subscribe(input_topic_,10,&packets_filter::packets_callback_,this);
    return;
}

void packets_filter::packets_callback_(const velodyne_msgs::VelodyneScan::ConstPtr msg)
{
    velodyne_msgs::VelodyneScan publish_packets;
    publish_packets.header = msg->header;
    for(auto packet_itr = msg->packets.begin(); packet_itr != msg->packets.end(); packet_itr++)
    {
        std::size_t azimuth_data_pos = 100*0+2;
        int azimuth = *( (u_int16_t*) (&packet_itr->data[azimuth_data_pos]));
        if(cut_start_angle_ < cut_end_angle_)
        {
            if(cut_start_angle_ <= azimuth && azimuth <= cut_end_angle_)
            {
                publish_packets.packets.push_back(*packet_itr);
            }
        }
        else
        {
            if(cut_start_angle_ <= azimuth && azimuth <= 35999)
            {
                publish_packets.packets.push_back(*packet_itr);
            }
            else if(0 <= azimuth && azimuth <= cut_end_angle_)
            {
                publish_packets.packets.push_back(*packet_itr);
            }
        }
    }
    packets_pub_.publish(publish_packets);
    return;
}