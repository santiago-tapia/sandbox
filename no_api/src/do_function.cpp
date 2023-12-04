
#include "no_api/do_function.hpp"

void do_function(
  const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
  std::shared_ptr<std_srvs::srv::SetBool::Response> response,
  const InputState & st)
{
  //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), request->data ? "Activate" : "Deactivate");
  response->success = request->data ? st.a < st.b : st.a > st.b;
  response->set__message("Ok");
}
