#include <ros/ros.h>
#include "tutorial2/AddTwoInts.h"


int main(int argc, char **argv){
    ros::init(argc, argv, "Service_client");
    ros::NodeHandle nh;
    
    ros::ServiceClient client = nh.serviceClient<tutorial2::AddTwoInts>("add_two_ints");
    tutorial2::AddTwoInts srv;
    srv.request.a = 2;
    srv.request.b = 4;

    if(client.call(srv)){
        ROS_INFO("The sum of your integers : %ld", srv.response.sum);
    }
    else{
        ROS_INFO("Failed to call Service");
        return 1;
    }
    return 0;
}