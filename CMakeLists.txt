cmake_minimum_required(VERSION 3.5)
project(beginner_tutorials)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# find_package(example_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
 
  "srv/StringChange.srv"
  # DEPENDENCIES geometry_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
# find_package(beginner_tutorials REQUIRED)          

add_executable(talker src/publisher_member_function.cpp)
add_executable(listner src/subscriber_member_function.cpp)
add_executable(server src/server_string.cpp)
add_executable(client src/client_string.cpp)

rosidl_target_interfaces(server
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(client
  ${PROJECT_NAME} "rosidl_typesupport_cpp")


ament_target_dependencies(talker rclcpp std_msgs )
ament_target_dependencies(listner rclcpp std_msgs)
ament_target_dependencies(server rclcpp std_msgs)
ament_target_dependencies(client rclcpp std_msgs)



install(TARGETS
  talker
  listner
  server
  client
  DESTINATION lib/${PROJECT_NAME})

ament_package()
