/*
Copyright 2022 Naveen Mangla
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

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

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na:%s,b:%s",
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
