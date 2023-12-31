cmake_minimum_required(VERSION 3.8)
project(prototype)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Winvalid-pch)
endif()

# find dependencies
set(PROJECT_DEPENDENCIES
  ament_cmake
)

message(STATUS "Looking for dependencies")

foreach(DEPENDENCY ${PROJECT_DEPENDENCIES})
  find_package(${DEPENDENCY} REQUIRED)
  if(${DEPENDENCY}_FOUND)
    message(STATUS "${DEPENDENCY} was found")
  else()
    message(STATUS "${DEPENDENCY} was not found")
  endif()
endforeach()

include_directories(
  include
  include/${PROJECT_NAME}
)

set(SOURCE_CPP_FILES_MAIN
  src/main.cpp
  src/logic_a/logic_a.cpp
)

add_executable(main ${SOURCE_CPP_FILES_MAIN})
target_include_directories(main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(main PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(main ${PROJECT_DEPENDENCIES})

# target_precompile_headers(main
#   PRIVATE
#     [["rclcpp/rclcpp.hpp"]]
# )

install(TARGETS main
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
