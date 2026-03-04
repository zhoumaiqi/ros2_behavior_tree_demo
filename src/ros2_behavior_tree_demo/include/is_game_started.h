#ifndef IS_GAME_STARTED_H
#define IS_GAME_STARTED_H

#include <behaviortree_cpp_v3/condition_node.h>

class IsGameStarted : public BT::ConditionNode
{
public:
    IsGameStarted(const std::string& name, const BT::NodeConfiguration& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::InputPort<bool>("game_started") };
    }

    BT::NodeStatus tick() override {
        bool game_started;
        if (!getInput<bool>("game_started", game_started)) {
            throw BT::RuntimeError("missing required input [game_started]");
        }
        return game_started ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
    }
};

#endif // IS_GAME_STARTED_H