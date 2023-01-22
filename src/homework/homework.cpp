#include "ros/ros.h"
#include "test1/add.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include <sstream>

bool add(test1::add::Request  &req,
         test1::add::Response &res, int Y)
{
    ros::NodeHandle n;
    //int Y;
    //n.getParam("msg", Y);
    res.sum = req.X + Y;
    n.setParam("msg", res.sum);
    ROS_INFO("request: x=%ld", (long int)req.X);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}

//int main(int argc, char **argv)
//{
//    ros::init(argc, argv, "Add");
//    ros::NodeHandle n;
//    ros::ServiceServer service = n.advertiseService("add_service_server", add);
//    ROS_INFO("Ready to add two ints.");
//    ros::spin();
//
//    return 0;
//}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_service");
    ros::NodeHandle n;
    ros::
    ros::Publisher publisher = n.advertise<std_msgs::Int32>("publisher", 1000);
    ros::ServiceServer service = n.advertiseService("add_service", add);
    //n.setParam("msg", 0);
    ros::Rate loop_rate(10);
    std_msgs::Int32 msg;
    msg.data = 0;
    while (ros::ok())
    {
        //std_msgs::Int32 msg;
        //n.getParam("msg", msg.data);
        //msg.data = x;
        //ROS_INFO("%d", x);
        publisher.publish(msg);
        if (ros::service::call("service", add, msg.data)){
            ROS_INFO("test")
        }
        //std::cout << msg.data;
        //ROS_INFO("I said: [%s]", msg->data.c_str());

        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}
