[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
---
# Publisher and Subscriber in ROS2

### Overview

This is a ROS Package that defines a basic publisher and subscriber with custom message.

### Dependencies/ Assumptions
- OS : Ubuntu 20.04 
- ROS2 Distro : ROS2 Galactic
- Package build type : ```ament_cmake ```
- Package dependencies : ```rclcpp```, ```std_msgs``` 
- ROS2 galactic Installation : [link](https://automaticaddison.com/how-to-install-ros-2-galactic-fitzroy-on-ubuntu-linux/)

## How to Run the ROS Package
### Build Instructions
```
cd <your_ROS2_ws>/src
git clone https://github.com/nvnmangla/beginner_tutorials.git
cd ..   
rosdep install -i --from-path src --rosdistro galactic -y
colcon build --packages-select beginner_tutorials
source . install/setup.bash
source ~/<your ROS2 installation>/install/local_setup.bash
```

### Run Publisher
To run the publisher node, open a new terminal and run:
```
cd <your_ROS2_ws>
. install/setup.bash
ros2 run beginner_tutorials talker
```
### Run Subscriber
To run the subscriber node, open a new terminal and run:
```
cd <your_ROS2_ws>
. install/setup.bash
ros2 run beginner_tutorials listener
```

### Run Server
This will merge two different strings
To run the server node, open a new terminal and run:
```
cd <your_ROS2_ws>
. install/setup.bash
ros2 run beginner_tutorials server
```

### Run Client
To run the client node, open a new terminal and run:
```
cd <your_ROS2_ws>
. install/setup.bash
ros2 run beginner_tutorials client <string 1> <string 2>
```
## Launch
To run the client node, open a new terminal and run:
```
cd <your_ROS2_ws>/src/beginners_tutorials/launch
```
If you want to record bag
```
ros2 launch nodes.yaml ros_record:=true
```
else:
```
ros2 launch nodes.yaml ros_record:=false
```
## Play Bag

```
cd <your_ROS2_ws>src/beginners_tutorials/results/bag
ros2 play bag <bag_file>
```

## Testing 
Without Verbose output
```
colcon test --packages-select beginner_tutorials
```
With Verbose output
```
colcon test --event-handlers console_direct+ --packages-select beginner_tutorials
```


## Results
The results after running the following commands are stored in the <your_package>/results folder. This inclues Bag folder as well

### cppcheck
Run the following command from the root directory of your ROS package
```
cppcheck --enable=all --std=c++17 ./src/*.cpp --suppress=missingIncludeSystem --suppress=unmatchedSuppression --suppress=unusedFunction --suppress=missingInclude --suppress=useInitializationList > results/cppcheck.txt
```
### cpplint
Run the following command from the root directory of your ROS package
```
 cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order ./src/*.cpp > ./results/cpplint.txt
```
