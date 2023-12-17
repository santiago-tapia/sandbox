#include "rclcpp/rclcpp.hpp"

void tick()
{
  static int count_ = 0;
  RCLCPP_INFO(rclcpp::get_logger("tick"), "doing tick", "count: %d", count_);
  ++count_;
}
