#include "ros/ros.h"
#include "test1/add.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include <sstream>

std_msgs::Int32 msg;
bool add(test1::add::Request  &req,
         test1::add::Response &res)
{
    res.sum = req.X + msg.data;
    msg.data = res.sum;
    ROS_INFO("request: x=%ld", (long int)req.X);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}



int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_service");
    ros::NodeHandle n;
    msg.data = 0;
    ros::Publisher publisher1 = n.advertise<std_msgs::Int32>("topic", 1000);
    ros::ServiceServer service = n.advertiseService("add_service", add);
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        publisher1.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
