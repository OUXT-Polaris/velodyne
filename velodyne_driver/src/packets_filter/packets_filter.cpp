#include <packets_filter/packets_filter.h>

packets_filter::packets_filter()
{

}

packets_filter::~packets_filter()
{

}

void packets_filter::init()
{
    packets_pub_ = nh_.advertise<velodyne_msgs::VelodyneScan>(ros::this_node::getName()+"/filtered_packets",10);
    return;
}

void packets_filter::subscribe()
{
    packets_sub_ = nh_.subscribe(ros::this_node::getName()+"/raw_packets",10,&packets_filter::packets_callback_,this);
    return;
}

void packets_filter::unsubscribe()
{
    return;
}

void packets_filter::packets_callback_(const velodyne_msgs::VelodyneScan::ConstPtr msg)
{
    return;
}