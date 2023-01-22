#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include <sstream>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher1");
    ros::NodeHandle n;
    ros::Publisher publisher1 = n.advertise<std_msgs::Int32>("publisher1", 1000);
    n.setParam("msg", 0);
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        std_msgs::Int32 msg;
        n.getParam("msg", msg.data);
        //msg.data = x;
        //ROS_INFO("%d", x);
        publisher1.publish(msg);
        //std::cout << msg.data;
        //ROS_INFO("I said: [%s]", msg->data.c_str());


        ros::spinOnce();

        loop_rate.sleep();
    }


    return 0;
}