#include "z1_tsid/target_pose_interactive_marker.hpp"

#include <rclcpp/executors.hpp>
#include <rclcpp/node.hpp>
#include <visualization_msgs/msg/interactive_marker.hpp>
#include <visualization_msgs/msg/marker.hpp>

namespace tsid {

class TargetPoseNode : public rclcpp::Node {

private:
  rclcpp::Publisher<visualization_msgs::msg::InteractiveMarker>::SharedPtr
      _marker_publisher;
  visualization_msgs::msg::InteractiveMarker _marker;

public:
  TargetPoseNode() : Node("target_pose_im_node") {
      using visualization_msgs::msg::InteractiveMarker;
      _marker_publisher = create_publisher<InteractiveMarker>("/target_pose", rclcpp::QoS(10));
  };

  void publish_marker() {
      _marker_publisher->publish(_marker);
  }
};
} // namespace tsid

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<tsid::TargetPoseNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
