# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 3.0.2)
project(test1)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

add_service_files(
  FILES
  serviceTest.srv
  add.srv
)

## Declare ROS messages and services
add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pub src/publisher/pub.cpp)
target_link_libraries(pub ${catkin_LIBRARIES})
add_dependencies(pub test1_generate_messages_cpp)

add_executable(sub src/subscriber/sub.cpp)
target_link_libraries(sub ${catkin_LIBRARIES})
add_dependencies(sub test1_generate_messages_cpp)

add_executable(service src/service/service.cpp)
target_link_libraries(service ${catkin_LIBRARIES})
add_dependencies(service test1_generate_messages_cpp)

add_executable(client src/client/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client test1_generate_messages_cpp)

add_executable(homework src/homework/homework.cpp)
target_link_libraries(homework ${catkin_LIBRARIES})
add_dependencies(homework test1_generate_messages_cpp)

# %EndTag(FULLTEXT)%
