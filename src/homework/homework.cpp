#include "ros/ros.h"
#include "test1/add.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include <sstream>

std_msgs::Int32 msg;
msg.data = 0;

bool add(test1::add::Request  &req,
         test1::add::Response &res, int Y)
{
    res.sum = req.X + Y;
    msg.data = res.sum;
    ROS_INFO("request: x=%ld", (long int)req.X);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}



int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_service");
    ros::NodeHandle n;
    ros::Publisher publisher1 = n.advertise<std_msgs::Int32>("topic", 1000);
    ros::ServiceServer service = n.advertiseService("add_service", add(msg.data));
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        publisher.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}
