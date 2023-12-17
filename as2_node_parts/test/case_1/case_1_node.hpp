#ifndef CASE_1_NODE__HPP
#define CASE_1_NODE__HPP

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int16.hpp"

#include "as2_node_parts/np_template_node.hpp"
#include "input_state.hpp"
#include "inner_state.hpp"

class case_1_node : public np_template_node<input_state, inner_state>
{
public:
  case_1_node(const rclcpp::NodeOptions & options);
  virtual ~case_1_node() = default;

  virtual void tick(const input_state &, inner_state &) override;

private:
  using ThingSubscription = typename rclcpp::Subscription<std_msgs::msg::String>::SharedPtr;
  ThingSubscription thing_subscription_;

  using NumberSubscription = typename rclcpp::Subscription<std_msgs::msg::UInt16>::SharedPtr;
  NumberSubscription number_subscription_;
};

#endif  // CASE_1_NODE__HPP
