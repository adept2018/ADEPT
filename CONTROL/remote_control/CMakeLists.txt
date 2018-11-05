cmake_minimum_required(VERSION 2.8.3)
project(remote_control)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp 
					  src/carstate.cpp 
					  src/idle.cpp 
					  src/forward.cpp 
					  src/left.cpp 
					  src/right.cpp 
					  src/leftforward.cpp 
					  src/rightforward.cpp 
					  src/backward.cpp 
					  src/left.cpp
					  src/right.cpp 
					  src/leftbackward.cpp
					  src/rightbackward.cpp 
					  src/avoid.cpp 
					  #src/path.cpp 
					  )
target_link_libraries(talker ${catkin_LIBRARIES} curl)
add_dependencies(talker beginner_tutorials_generate_messages_cpp)

