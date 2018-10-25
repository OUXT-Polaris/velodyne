#include <packets_filter/packets_filter.h>

packets_filter::packets_filter()
{

}

packets_filter::~packets_filter()
{

}

void packets_filter::init()
{
    ros::NodeHandle private_nh("~");
    private_nh.param<std::string>("input_topic",input_topic_,ros::this_node::getName()+"/raw_packets");
    packets_sub_ = nh_.subscribe(input_topic_,10,&packets_filter::packets_callback_,this);
    private_nh.param<std::string>("output_topic",output_topic_,ros::this_node::getName()+"/filtered_packets");
    double cut_start_angle_d,cut_end_angle_d;
    private_nh.param<double>("cut_start_angle",cut_start_angle_d,0);
    if(cut_start_angle_d < 0 || cut_start_angle_d > 2*M_PI)
    {
        ROS_ERROR_STREAM("invalid value. cut_start_angle must be 0 to 2*Pi");
        cut_start_angle_d = 0;
    }
    if(cut_end_angle_d < 0 || cut_end_angle_d > 2*M_PI)
    {
        ROS_ERROR_STREAM("invalid value. cut_end_angle must be 0 to 2*Pi");
        cut_end_angle_d = 0;
    }
    private_nh.param<double>("cut_end_angle",cut_end_angle_d,0);
    cut_start_angle_ = (int)(100 * cut_start_angle_d);
    cut_end_angle_ = (int)(100*cut_end_angle_d);
    packets_pub_ = nh_.advertise<velodyne_msgs::VelodyneScan>(output_topic_,10);
    return;
}

void packets_filter::packets_callback_(const velodyne_msgs::VelodyneScan::ConstPtr msg)
{
    for(auto packet_itr = msg->packets.begin(); packet_itr != msg->packets.end(); packet_itr++)
    {
        std::size_t azimuth_data_pos = 100*0+2;
        int azimuth = *( (u_int16_t*) (&packet_itr->data[azimuth_data_pos]));
    }
    return;
}