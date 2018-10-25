#ifndef PACKETS_FILTER_H_INCLUDED
#define PACKETS_FILTER_H_INCLUDED

#include <ros/ros.h>
#include <velodyne_msgs/VelodyneScan.h>

class packets_filter
{
    public:
        packets_filter();
        ~packets_filter();
        void init(ros::NodeHandle private_nh);
    private:
        ros::NodeHandle nh_;
        std::string input_topic_;
        int cut_start_angle_,cut_end_angle_;
        ros::Subscriber packets_sub_;
        std::string output_topic_;
        ros::Publisher packets_pub_;
        void packets_callback_(const velodyne_msgs::VelodyneScan::ConstPtr msg);
};

#endif  //PACKETS_FILTER_H_INCLUDED