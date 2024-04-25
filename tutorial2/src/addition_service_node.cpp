#include <ros/ros.h>
#include "tutorial2/AddTwoInts.h"

bool add(tutorial2::AddTwoInts::Request &req, tutorial2::AddTwoInts::Response &res){
    res.sum = req.a + req.b;
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "Service_Node");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("add_two_ints", add);
    ros::spin();
    return 0;
}