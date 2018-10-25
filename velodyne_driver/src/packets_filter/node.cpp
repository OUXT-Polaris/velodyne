#include <ros/ros.h>
#include <packets_filter/packets_filter.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "velodyne_node");
  ros::spin();
  return 0;
}