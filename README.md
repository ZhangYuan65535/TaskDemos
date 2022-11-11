本仓库中存放的都是我的实习 Demo，各 Demo 实现的目标如下：

### Demo_1

目标：实现一套插件系统 UI 程序，加上一个服务端程序。

详情：实现一个计算器小程序，命令行输入输出，插件提供 GUI 功能。

### Demo_2

目标：使用 CMake 进行项目管理。

详情：将 Demo_1 的源码拿过来，使用 CMake 进行重新构建。

### Demo_3

目标：接口保持二进制兼容

详情：编写测试程序，已实现二进制兼容。并使用多种方式破坏程序的二进制兼容性。

### Demo_4 (working)

目标：使用 MVC 或其它耦合性低的设计模式。

详情：使用 Decorator 模式编写测试程序，该设计模式有利于将来功能的拓展。

### Demo_5 (working)

目标：同时使用 GSettings 与 DConfig 进行配置。

详情：整体实现为一个 “防疫程序”，通过 GSettings 读取居民信息。程序中，居民的信息存储、展示用到了 Qt 的 MVD 模型，并加入自绘控件。

### Demo_6 (working)

目标：至少实现一种自绘控件。

详情：目前已经实现了温度计功能，如下图所示。还打算实现一个搜索框控件，目前还在开发中。

### Demo_7

目标：使用 view/mode/delegate 模型。

详情：整体实现为一个极简启动器，所有应用程序的数据存放在 mode 中，通过 view 来显示所有 item，item 的渲染由 delegate 负责。

### Demo_8

目标：使用多线程

详情：编写一个测试程序，其中用到了 Qt 的四种多线程方法，分别是

+ 继承 QThread
+ 使用 moveToThread
+ QRunnable 结合线程池
+ 使用 QtConcurrent

### Demo_11

目标：练习单元测试

详情：整体实现为一个自定义版 String 类，实现了 STL string 中的部分功能。

### Demo_total

目标：将所有需要的功能聚合在一个项目中

详情：整体实现为 C/S 架构，Client 负责接收用户输入的数据，Server 负责处理 Client 传来的数据，C/S 之间的通信借助 QDBus。















