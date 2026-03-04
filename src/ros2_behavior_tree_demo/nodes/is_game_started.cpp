#include "is_game_started.h"
#include <behaviortree_cpp_v3/behavior_tree.h>
#include <behaviortree_cpp_v3/bt_factory.h>

// 需要在全局命名空间中使用 BT_REGISTER_NODES 宏
BT_REGISTER_NODES(factory)
{
    factory.registerNodeType<IsGameStarted>("IsGameStarted");
}