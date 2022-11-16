/**
 * @file client_string.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Client node 
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <chrono>
#include <cstdlib>
#include <memory>

#include "beginner_tutorials/srv/string_change.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node =
      rclcpp::Node::make_shared("string_change_client");
  rclcpp::Client<beginner_tutorials::srv::StringChange>::SharedPtr client =
      node->create_client<beginner_tutorials::srv::StringChange>(
          "string_change");

  auto request =
      std::make_shared<beginner_tutorials::srv::StringChange::Request>();
  request->a = argv[1];
  request->b = argv[2];

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_FATAL(rclcpp::get_logger("rclcpp"),
                   "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_INFO_STREAM(
        rclcpp::get_logger("rclcpp"),
        "Final String: " << result.get()->sum);  // Printing the final string
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                 "Failed to call service string_change");
  }

  rclcpp::shutdown();
  return 0;
}
