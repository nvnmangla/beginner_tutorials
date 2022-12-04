

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
 * @file test.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Testing function
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>
#include <minial_publisher.hpp>


TEST(MinimalPublisher, rclcppOK) {
  std::cout << "Checking ROS OK!!" << std::endl;
  EXPECT_TRUE(rclcpp::ok());
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    rclcpp::shutdown();
    std::cout << "DONE SHUTTING DOWN ROS" << std::endl;
    return result;
}
