cmake_minimum_required(VERSION 2.8.3)
project(basic_motion_planner)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  nav_msgs
  sensor_msgs
  geometry_msgs
  pcl_ros
  pcl_conversions
  ackermann_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(
  bmp
  src/basic_motion_planner.cpp
  src/motion_computer.cpp
  src/laserscan_to_pointcloud.cpp
)

target_link_libraries(bmp
  ${catkin_LIBRARIES}
)
