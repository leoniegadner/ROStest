#include "ros/ros.h"
#include "test1/add.h"
#include <cstdlib>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_client");
//    if (argc != 2)
//    {
//        ROS_INFO("usage: add X");
//        return 1;
//    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<test1::add>("add_service");
    test1::add srv;
    srv.request.X = atoll(argv[1]);
    if (client.call(srv))
    {
        ROS_INFO("Set Param to: %ld", (long int)srv.response.sum);
        n.setParam("msg", srv.response.sum);
    }
    else
    {
        ROS_ERROR("Failed to call service ");
        return 1;
    }

    return 0;
}
