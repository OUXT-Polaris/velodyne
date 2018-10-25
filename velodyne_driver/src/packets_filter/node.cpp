#include <ros/ros.h>
#include <packets_filter/packets_filter.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "velodyne_node");
  packets_filter filter;
  ros::NodeHandle pnh("~");
  filter.init(pnh);
  ros::spin();
  return 0;
}