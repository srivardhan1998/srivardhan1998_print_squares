#include "ros/ros.h"
#include "std_msgs/Int64.h"
ros::Publisher topic_squares_pub;

void chatterCallback(const std_msgs::Int64::ConstPtr &msg){
  std_msgs::Int64 x;
  x.data=msg->data*msg->data;
  ROS_INFO("squares read %ld", x.data);
  topic_squares_pub.publish(msg);
}

int main(int argc, char **argv){
  
  ros::init(argc, argv, "srivardhan1998_squares");

  ros::NodeHandle num;
  topic_squares_pub = num.advertise<std_msgs::Int64>("topic_squares", 1000);
  ros::Subscriber sub = num.subscribe("topic_numbers", 1000, chatterCallback);

  ros::spin();

  return 0;
}

