#ifndef CASE_1_NODE_TESTER__HPP
#define CASE_1_NODE_TESTER__HPP

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int16.hpp"

class case_1_node_tester : public rclcpp::Node
{
public:
  case_1_node_tester(const rclcpp::NodeOptions & options);
  ~case_1_node_tester() = default;

  void send();

private:
  using ThingPublisher = typename rclcpp::Publisher<std_msgs::msg::String>::SharedPtr;
  ThingPublisher thing_publisher_;
  using NumberPublisher = typename rclcpp::Publisher<std_msgs::msg::UInt16>::SharedPtr;
  NumberPublisher number_publisher_;
};

#endif  // CASE_1_NODE_TESTER__HPP
