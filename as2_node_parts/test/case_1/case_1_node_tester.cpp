#include "case_1_node_tester.hpp"

case_1_node_tester::case_1_node_tester(const rclcpp::NodeOptions & options)
: rclcpp::Node("case_1_tester", options)
{
  thing_publisher_ = this->create_publisher<std_msgs::msg::String>("thing", 10);
  number_publisher_ = this->create_publisher<std_msgs::msg::UInt16>("number", 10);
}

void case_1_node_tester::send()
{
  std_msgs::msg::String str;
  str.data = "hello";
  this->thing_publisher_->publish(str);
  std_msgs::msg::UInt16 num;
  num.data = 13;
  this->number_publisher_->publish(num);
}
