#include "ros/ros.h"
#include "test1/serviceTest.h"

bool add(test1::serviceTest::Request  &req,
         test1::serviceTest::Response &res)
{
    res.sum = req.A + req.B;
    ROS_INFO("request: x=%ld, y=%ld", (long int)req.A, (long int)req.B);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_server_node");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("service_server", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}