#ifndef PACKETS_FILTER_H_INCLUDED
#define PACKETS_FILTER_H_INCLUDED

#include <ros/ros.h>
#include <velodyne_msgs/VelodyneScan.h>

class packets_filter
{
    public:
        packets_filter();
        ~packets_filter();
        void init();
        void subscribe();
        void unsubscribe();
    private:
        ros::NodeHandle nh_;
        ros::Subscriber packets_sub_;
        ros::Publisher packets_pub_;
        void packets_callback_(const velodyne_msgs::VelodyneScan::ConstPtr msg);
};

#endif  //PACKETS_FILTER_H_INCLUDED