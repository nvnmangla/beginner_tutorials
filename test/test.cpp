

#include <gtest/gtest.h>
#include <minial_publisher.hpp>


TEST(MinimalPublisher, TrueIsTrueTest) {
  std::cout << "TEST BEGINNING!!" << std::endl;

//   EXPECT_TRUE(true);
}

int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    rclcpp::shutdown();
    std::cout << "DONE SHUTTING DOWN ROS" << std::endl;
    return result;
}
