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
 * @file minial_publisher.hpp
 * @author your name (you@domain.com)
 * @brief Publisher class
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <chrono>
#include <memory>
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "tf2_ros/transform_broadcaster.h"

using namespace std::chrono_literals;

/**
 * @brief This will start /chatter and 
 * /tf topics
 */
class MinimalPublisher : public rclcpp::Node {
 public:
 /**
  * @brief Construct a new Minimal Publisher Node 
  * 
  */
  MinimalPublisher() : Node("minimal_publisher"), count_(0) {
    // this is TF Broadcaster
    tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
    publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

 private:
  void timer_callback() {
    auto message = std_msgs::msg::String();
    message.data = "Hey! How you doin.." + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    geometry_msgs::msg::TransformStamped t;

    //  TF Transformations.
    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "world"; // World frame
    t.child_frame_id = "talk"; // Talk frame
    t.transform.translation.x = 2.0;
    t.transform.translation.y = 2.0;
    t.transform.translation.z = 1.0;
    t.transform.rotation.x = 1.0;
    t.transform.rotation.y = 1.0;
    t.transform.rotation.z = 0.0;
    t.transform.rotation.w = 1.0;

    tf_broadcaster_->sendTransform(t); // send Transform
    publisher_->publish(message); // publish message
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
  std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};


