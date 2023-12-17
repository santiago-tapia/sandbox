
find_package(ament_cmake_gtest REQUIRED)
find_package(std_msgs REQUIRED)

set(TEST_CPP_FILES
  case_1/case_1_node.cpp
  case_1/case_1_node_tester.cpp
)

ament_add_gtest(${PROJECT_NAME}_test ${PROJECT_NAME}_main.cpp ${TEST_CPP_FILES})
ament_target_dependencies(${PROJECT_NAME}_test ${PROJECT_DEPENDENCIES} std_msgs)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
