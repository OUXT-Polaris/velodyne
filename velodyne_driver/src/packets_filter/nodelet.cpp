#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>

namespace velodyne_driver
{
    class PacketsFilterNodelet : public nodelet::Nodelet
    {
    public:
        PacketsFilterNodelet(){};
        ~PacketsFilterNodelet(){};
        virtual void onInit(){};
    };
}

PLUGINLIB_EXPORT_CLASS(velodyne_driver::PacketsFilterNodelet, nodelet::Nodelet)