#include "case_1_node.hpp"

case_1_node::case_1_node(const rclcpp::NodeOptions & options)
: np_template_node(options)
{
  auto thing_cb = [this](const std_msgs::msg::String & msg) {
      this->received += 1; // for testing
      this->thing = msg.data;
    };
  thing_subscription_ = this->create_subscription<std_msgs::msg::String>("thing", 10, thing_cb);

  auto number_cb = [this](const std_msgs::msg::UInt16 & msg) {
      this->received += 1; // for testing
      this->number = msg.data;
    };
  number_subscription_ = this->create_subscription<std_msgs::msg::UInt16>("number", 10, number_cb);
}

void case_1_node::tick(const input_state &, inner_state &) {}
