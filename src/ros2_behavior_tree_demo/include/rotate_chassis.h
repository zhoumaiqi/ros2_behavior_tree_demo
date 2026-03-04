#ifndef ROTATE_CHASSIS_H
#define ROTATE_CHASSIS_H

#include <behaviortree_cpp_v3/action_node.h>

class RotateChassis : public BT::SyncActionNode
{
public:
    RotateChassis(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::InputPort<double>("angle") };
    }

    BT::NodeStatus tick() override {
        double angle;
        if (!getInput<double>("angle", angle)) {
            throw BT::RuntimeError("missing required input [angle]");
        }
        std::cout << "RotateChassis tick: rotating by " << angle << " degrees" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

#endif // ROTATE_CHASSIS_H