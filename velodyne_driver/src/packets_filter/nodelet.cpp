#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>

#include <packets_filter/packets_filter.h>

namespace velodyne_driver
{
    class PacketsFilterNodelet : public nodelet::Nodelet
    {
    public:
        PacketsFilterNodelet(){};
        ~PacketsFilterNodelet(){};
        virtual void onInit()
        {
            ros::NodeHandle nh = getNodeHandle();
            ros::NodeHandle private_nh = getPrivateNodeHandle();
            filter_.init(nh,private_nh);
        };
    private:
        packets_filter filter_;
    };
}

PLUGINLIB_EXPORT_CLASS(velodyne_driver::PacketsFilterNodelet, nodelet::Nodelet)