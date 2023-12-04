cmake_minimum_required(VERSION 3.8)
project(no_api)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
set(PROJECT_DEPENDENCIES
  ament_cmake
  rclcpp
  rclcpp_components
  std_srvs
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

set(SOURCE_CPP_FILES_NO_API
  src/details/no_api_node.cpp
  src/do_function.cpp
)

add_executable(no_api_program src/main.cpp ${SOURCE_CPP_FILES_NO_API})
target_include_directories(no_api_program PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(no_api_program PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(no_api_program ${PROJECT_DEPENDENCIES})

install(TARGETS no_api_program
  DESTINATION lib/${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED ${SOURCE_CPP_FILES_NO_API})
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

ament_target_dependencies(${PROJECT_NAME} ${PROJECT_DEPENDENCIES})

rclcpp_components_register_nodes(${PROJECT_NAME} "no_api_node")

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(${PROJECT_DEPENDENCIES})

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
  
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
