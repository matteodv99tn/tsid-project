cmake_minimum_required(VERSION 3.8)
project(z1_tsid)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


#  ____                            _                 _
# |  _ \  ___ _ __   ___ _ __   __| | ___ _ __   ___(_) ___  ___
# | | | |/ _ \ '_ \ / _ \ '_ \ / _` |/ _ \ '_ \ / __| |/ _ \/ __|
# | |_| |  __/ |_) |  __/ | | | (_| |  __/ | | | (__| |  __/\__ \
# |____/ \___| .__/ \___|_| |_|\__,_|\___|_| |_|\___|_|\___||___/
#            |_|

set(ROS2_REQUIRED_COMPONENTS
    tsid_controller
    z1_description
    rclcpp
    visualization_msgs
    )
foreach(COMPONENT ${ROS2_REQUIRED_COMPONENTS})
    find_package(${COMPONENT} REQUIRED)
endforeach()

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(
    target_marker
    src/target_pose_interactive_marker.cpp
    )
target_include_directories(
    target_marker
    PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    # $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
    )


ament_target_dependencies(target_marker ${ROS2_REQUIRED_COMPONENTS})

#  ___           _        _ _
# |_ _|_ __  ___| |_ __ _| | |
#  | || '_ \/ __| __/ _` | | |
#  | || | | \__ \ || (_| | | |
# |___|_| |_|___/\__\__,_|_|_|
#

install(
    DIRECTORY launch config
    DESTINATION share/${PROJECT_NAME}
    )
install(
    DIRECTORY include/
    DESTINATION include
    )
install(
    TARGETS target_marker
    DESTINATION lib/target_marker
    )

ament_export_dependencies(${ROS2_REQUIRED_COMPONENTS})
ament_package()
