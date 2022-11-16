/**
 * @file server_string.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Server Node
 * @version 0.1
 * @date 2022-11-16
 * @copyright Copyright (c) 2022
 */
#include <memory>
#include <rclcpp/logging.hpp>
#include "beginner_tutorials/srv/string_change.hpp"
#include "rclcpp/rclcpp.hpp"
void schange(
    const std::shared_ptr<beginner_tutorials::srv::StringChange::Request>
        request,
    std::shared_ptr<beginner_tutorials::srv::StringChange::Response> response) {
  response->sum = request->a + " " + request->b;

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na:%s , b:%s",
              request->a.c_str(), request->b.c_str());
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response:%s",
              response->sum.c_str());
}
int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> node =
      rclcpp::Node::make_shared("string_change_server");
  rclcpp::Service<beginner_tutorials::srv::StringChange>::SharedPtr service =
      node->create_service<beginner_tutorials::srv::StringChange>(
          "string_change", &schange);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to change Strings.");
  rclcpp::spin(node);
  rclcpp::shutdown();
}
