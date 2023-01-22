#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
    ROS_INFO("I heard: [%d]", msg->data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("topic", 1000, chatterCallback);
    ros::spin();

    return 0;
}