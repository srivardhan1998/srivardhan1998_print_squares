#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "srivardhan1998_numbers");
  ros::NodeHandle num;
  ros::Publisher topic_numbers_pub = num.advertise<std_msgs::Int64>("topic_numbers", 1000);

  ros::Rate loop_rate(1);
  int count = 1;
  while (ros::ok())
  {
    std_msgs::Int64 msg;

    msg.data = count;

    ROS_INFO("numbers published %ld", msg.data);
    topic_numbers_pub.publish(msg);

    ros::spinOnce();/*optional, used in case of */

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

