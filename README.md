## ROS 2 行为树演示（behavior_tree_demo）

本仓库包含一个简单的 **ROS 2** 包，展示如何使用 [BehaviorTree.CPP](https://github.com/BehaviorTree/BehaviorTree.CPP) 库来
构建和执行行为树。项目基于 `ament_cmake`，包名和源码目录现为 `ros2_behavior_tree_demo`。

仓库已经采用了描述性的 `ros2_behavior_tree_demo` 名称，包含相应的源码目录和包配置。

### 项目结构

```
src/my_behavior_tree_project/
	├── include/              # 自定义节点头文件
	│   ├── rotate_chassis.h
	│   └── is_game_started.h
	├── nodes/                # 节点实现与注册
	│   ├── rotate_chassis.cpp
	│   └── is_game_started.cpp
	├── trees/                # 行为树 XML 定义
	│   └── my_behavior_tree.xml
	└── main.cpp              # 入口：加载树并执行
```

### 功能概览

1. **IsGameStarted**  - 条件节点，从黑板读取 `game_started` 并返回成功/失败。
2. **RotateChassis**  - 同步动作节点，从黑板读取 `angle` 并打印调试信息。
3. 行为树在 XML 中定义：先检查游戏是否开始，然后执行旋转操作。

### 构建与运行

在工作区根目录下执行：

```powershell
colcon build --packages-select ros2_behavior_tree_demo
```

然后在同一环境中运行：

```powershell
ros2 run my_behavior_tree_project main
```

（此程序不依赖 ROS 节点，仅用于演示行为树执行过程。）

### 注意

• 若将包名在未来修改，请记得同时更新 `package.xml` 和 `CMakeLists.txt` 中的 `<name>` / `project()` 名称。
• 黑板变量在 `main.cpp` 中硬编码为 `game_started=true` 和 `rotation_angle=90.0`，用于演示。

欢迎将此示例扩展为实际机器人控制或比赛逻辑。

