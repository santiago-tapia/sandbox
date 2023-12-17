#ifndef NP_TEMPLATE_NODE__HPP
#define NP_TEMPLATE_NODE__HPP

#include "rclcpp/rclcpp.hpp"
#include "as2_node_parts/i_np_tick.hpp"

template<typename InputState, typename InnerState>
class np_template_node : public rclcpp::Node,
  public InnerState,
  public InputState,
  public i_np_tick<InputState, InnerState>
{
public:
  np_template_node(const rclcpp::NodeOptions & options)
  : rclcpp::Node("np_template_node", options)
  {
    double period_ = 0.1;
    try {
      this->get_parameter("period_ms", period_);  // Set if parameter is declared
    } catch (...) {
    }
    auto rate = std::chrono::duration<double>(period_);
    auto cb = [this]() {this->tick(*this, *this);};
    timer_ = this->create_wall_timer(rate, cb);
  }

  virtual ~np_template_node() = default;

private:
  rclcpp::TimerBase::SharedPtr timer_;
};

#endif  // TEMPLATE_NODE__HPP
