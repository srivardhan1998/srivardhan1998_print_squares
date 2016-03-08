#include "ros/ros.h"
#include "std_msgs/Int64.h"

void numb(const std_msgs::Int64::ConstPtr &msg){
  ROS_INFO("topic_numbers  %ld ", msg->data);
}
void sqrs(const std_msgs::Int64::ConstPtr &msg){
  ROS_INFO("topic_squares  %ld /n", msg->data);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "srivardhan1998_print");

  ros::NodeHandle num;
  ros::Rate loop_rate(1);

  ros::Subscriber sub1 = num.subscribe("topic_numbers", 1000, numb);
  loop_rate.sleep();
  ros::Subscriber sub2 = num.subscribe("topic_squares", 1000, sqrs);
 
  ros::spin();

  return 0;
}
