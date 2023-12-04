
#include "no_api_node.hpp"
#include "no_api/do_function.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

no_api_node::no_api_node(const std::string & name)
: rclcpp::Node(name)
{
  auto cb = [this](
              const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
              std::shared_ptr<std_srvs::srv::SetBool::Response> response) {
    this->do_service(request, response);
  };
  this->service = this->create_service<std_srvs::srv::SetBool>(name, cb);
}

no_api_node::no_api_node(const rclcpp::NodeOptions & options)
: rclcpp::Node("no_api", options)
{
  auto cb = [this](
              const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
              std::shared_ptr<std_srvs::srv::SetBool::Response> response) {
    this->do_service(request, response);
  };
  this->service = this->create_service<std_srvs::srv::SetBool>("no_api", cb);
}

void no_api_node::do_service(
  const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
  std::shared_ptr<std_srvs::srv::SetBool::Response> response)
{
  InputState st = {4, 11};
  do_function(request, response, st);
}

// Register Node as a component
#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(no_api_node)