#include <behaviortree_cpp_v3/bt_factory.h>
#include <iostream>
#include <fstream>
#include "rotate_chassis.h"
#include "is_game_started.h"

int main()
{
    BT::BehaviorTreeFactory factory;

    // 注册节点
    factory.registerNodeType<IsGameStarted>("IsGameStarted");
    factory.registerNodeType<RotateChassis>("RotateChassis");

    // 从XML文件加载行为树
    // 直接读取树定义文件，此处路径相对于工作目录
    std::ifstream xml_file("src/my_behavior_tree_project/trees/my_behavior_tree.xml");
    if (!xml_file)
    {
        std::cerr << "Failed to open XML file" << std::endl;
        return 1;
    }

    std::string xml_content((std::istreambuf_iterator<char>(xml_file)), std::istreambuf_iterator<char>());
    auto tree = factory.createTreeFromText(xml_content);

    // 设置黑板变量
    tree.rootBlackboard()->set("game_started", true);
    tree.rootBlackboard()->set("rotation_angle", 90.0);

    // 执行行为树
    BT::NodeStatus status = tree.tickRoot();
    std::cout << "Behavior Tree execution finished with status: " << BT::toStr(status) << std::endl;

    return 0;
}