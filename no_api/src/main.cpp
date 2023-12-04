#include "rclcpp/rclcpp.hpp"
#include "details/no_api_node.hpp"
#include "std_srvs/srv/set_bool.hpp"
#include <memory>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<no_api_node>("no_api_server");

  RCLCPP_INFO(node->get_logger(), "Ready to receive request.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}