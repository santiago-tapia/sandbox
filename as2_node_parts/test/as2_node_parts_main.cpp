#include "gtest/gtest.h"
#include "rclcpp/rclcpp.hpp"

#include "as2_node_parts/tick.hpp"
#include "case_1/case_1_node.hpp"
#include "case_1/case_1_node_tester.hpp"

#include "memory"

TEST(as2_node_parts_suite_test, test_tick) {
  tick();
}

TEST(as2_node_parts_suite_test, test_state)
{
  rclcpp::NodeOptions opts;
  auto c1 = std::make_shared<case_1_node>(opts);
  auto t1 = std::make_shared<case_1_node_tester>(opts);

  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(c1);
  executor.add_node(t1);

  t1->send();

  while (rclcpp::ok() && c1->received < 2) {
    executor.spin_some();
  }

  ASSERT_EQ(13, c1->number);
  ASSERT_EQ("hello", c1->thing);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
