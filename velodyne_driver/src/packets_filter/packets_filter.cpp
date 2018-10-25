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
    private_nh.param<std::string>("input_topic", input_topic_,ros::this_node::getName()+"/raw_packets");
    packets_sub_ = nh_.subscribe(input_topic_,10,&packets_filter::packets_callback_,this);
    private_nh.param<std::string>("output_topic",output_topic_,ros::this_node::getName()+"/filtered_packets");
    packets_pub_ = nh_.advertise<velodyne_msgs::VelodyneScan>(output_topic_,10);
    return;
}

void packets_filter::packets_callback_(const velodyne_msgs::VelodyneScan::ConstPtr msg)
{
    for(auto packet_itr = msg->packets.begin(); packet_itr != msg->packets.end(); packet_itr++)
    {

    }
    return;
}