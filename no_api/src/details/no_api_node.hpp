#ifndef NO_API_NODE_HPP
#define NO_API_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"

class no_api_node : public rclcpp::Node
{
public:
  no_api_node(const std::string & name);
  no_api_node(const rclcpp::NodeOptions & options);

  virtual ~no_api_node() = default;

  void do_service(
    const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
    std::shared_ptr<std_srvs::srv::SetBool::Response> response);

private:
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr service;
};

#endif  // NO_API_NODE_HPP
