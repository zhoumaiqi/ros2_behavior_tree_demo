cmake_minimum_required(VERSION 3.5)
project(ros2_behavior_tree_demo)

# 找到ament_cmake包
find_package(ament_cmake REQUIRED)

#找到rclcpp和std_msgs包
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 找到BehaviorTree.CPP包
find_package(behaviortree_cpp_v3 REQUIRED)

# 包含头文件路径
include_directories(
  ${behaviortree_cpp_v3_INCLUDE_DIRS}
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# 添加可执行文件
add_executable(main 
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/nodes/rotate_chassis.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/nodes/is_game_started.cpp
)

# 链接库
target_link_libraries(main 
  ${behaviortree_cpp_v3_LIBRARIES}
  ${rclcpp_LIBRARIES}
  ${std_msgs_LIBRARIES}
  )

# 声明ament依赖
ament_target_dependencies(main 
  behaviortree_cpp_v3 
  rclcpp 
  std_msgs)

# 添加共享库
add_library(behavior_tree_nodes SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/nodes/rotate_chassis.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/nodes/is_game_started.cpp
)

# 链接库
target_link_libraries(my_behavior_tree_nodes 
  ${behaviortree_cpp_v3_LIBRARIES}
  ${rclcpp_LIBRARIES}
  ${std_msgs_LIBRARIES}
)

# 声明ament依赖
ament_target_dependencies(my_behavior_tree_nodes 
  behaviortree_cpp_v3 
  rclcpp 
  std_msgs
)

# 安装目标
install(TARGETS main my_behavior_tree_nodes
  DESTINATION lib/${PROJECT_NAME})

ament_package()