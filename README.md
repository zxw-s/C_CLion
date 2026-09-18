# 项目名称

> 一句话描述项目，例：C语言练习，熟悉CLion

## 📖 项目介绍

基于 **CLion** 开发的控制台程序。包含整个C程序的完整结构：头文件、宏定义、全局变量、局部变量、函数、主函数、分支、循环、输出。

- 开发IDE：CLion
- 编程语言：C / C++ / C#
- 项目类型：控制台应用

## ⚙️ 环境依赖

### C / C++

1. CMake
2. C/C++编译器：MinGW-w64 / GCC / Clang
3. CLion自动读取`CMakeLists.txt`构建项目

### C#

1. .NET SDK
2. CLion自带.NET插件支持C#项目

## 🚀 编译与运行

### C / C++

1. 将仓库克隆到本地，使用CLion打开项目文件夹
2. CLion自动加载CMake配置，等待项目索引完成
3. 右上角选择构建目标（Debug / Release）
4. 点击运行按钮 ▶️ 或者快捷键 `Shift+F10` 运行程序
5. `Shift+F9` 启动调试

> 手动CMake命令（终端）

```bash
mkdir build && cd build
cmake ..
make
./程序名
```

### C#

1. CLion打开项目
2. .NET项目直接点击运行 ▶️

```bash
# 终端命令
dotnet build
dotnet run
```

## 📂 目录结构

```plaintext
ProjectName/
├─ CMakeLists.txt          # CMake构建脚本(C/C++)
├─ src/                    # 源代码目录
│  └─ main.c / main.cpp    # 主程序
├─ .gitignore              # Git忽略文件
└─ README.md               # 项目说明文档
```

> 说明：`cmake-build-debug/`、`.idea/` 由.gitignore过滤，不会提交到仓库

## ✨ 功能列表

- 功能1描述
- 功能2描述
- 待开发功能

## ❓ 常见问题

1. CMake加载失败：检查编译器路径配置，确认MinGW/GCC已安装
2. 中文乱码：CLion设置文件编码为UTF-8
3. 提交代码：`.gitignore` 已配置忽略编译产物、IDE缓存，无需手动删除
4. 找不到构建目标：刷新CMake项目

## 📄 许可证

MIT

## 使用提示

1. 放在项目根目录，和`.gitignore`同级
2. 如果只用C/C++，可以删掉C#段落；只用C#就删掉CMake相关内容
3. 修改项目名称、功能描述，按需增删内容

> CLion是JetBrains出品的专业 C/C++ IDE，默认**基于CMake构建系统**，自带智能提示、断点调试、代码格式化，必须搭配编译器MinGW‑w64 / MSVC；
> 
> **项目路径全部英文，禁止中文、空格**。
> 快捷键打开设置：`Ctrl+Alt+S`；导出配置备份：`File‑>Manage IDE Settings‑>Export Settings`。
> 
> 入门核心分4步：环境配置→新建项目→写代码运行→基础调试。

# 一、环境准备（工具链配置，最关键）

（一）**CLion下载**：社区版不存在，**学生可申请教育版免费**；普通用户付费。

（二）CLion 本身不带编译器，必须**先配置编译工具链**，三大系统配置方式：

**1.Windows**

编译器：**MinGW‑w64**（GCC/G++/GDB）

- 简易方案：直接用 CLion 自带的 MinGW（首次打开会自动提示下载，一路确认即可）

- 进阶方案：安装 MinGW-w64 / MSYS2，手动配置工具链，CLion可以内置下载工具链，

路径： `File → Settings → Build, Execution, Deployment → Toolchains` 

添加 MinGW，填写 gcc、g++、make 路径即可

- C编译器：`gcc.exe`

- C++编译器：`g++.exe`

- Debugger调试器：`gdb.exe`
  
  > 运行按钮灰色=CMake配置失败，工具链错误、CMakeLists语法错误。

**2.macOS**

打开终端执行：

```bash
xcode-select --install
```

安装命令行工具，CLion 会自动识别 clang 编译器

**3.Linux（Ubuntu/Debian）**

终端安装基础编译环境：

```bash
sudo apt install build-essential cmake gcc g++ gdb
```

CLion 自动识别工具链

# 二、新建项目

1. 打开 CLion，欢迎页Welcome → `New Project`
- 左侧选择C语言：`C Executable`；C++：`C++ Executable`
- 设置项目存放路径Location：纯英文路径
- 选择语言标准Language standard：C选C11；C++选C++17/20
- Create 创建项目。

项目自动生成2个核心文件：

- `main.cpp` ：主代码文件

-  `CMakeLists.txt` ：CMake构建配置文件（CLion项目核心）

自动生成的最简代码：

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, CLion!" << endl;
    return 0;
}
```

# 三、运行程序

**方式1**：点击编辑区右上角绿色三角 ▶️

**方式2**：快捷键  Shift+F10 

底部控制台会输出运行结果： Hello, CLion!

# 四、基础调试（CLion最强功能）

测试代码 main.cpp

```cpp
#include <iostream>
using namespace std;

int add(int a,int b){
    return a+b;
}

int main()
{
    int x=10,y=20;
    int res = add(x,y);
    cout<<"结果 = "<<res<<endl;
    return 0;
}
```

1. **构建**：锤子图标 `Ctrl+F9`
2. **运行**：绿色三角 ▶ `Shift+F10`
3. **Debug调试（CLion核心）**
- 在代码行号左侧点击打断点（出现红色圆点=断点）
- Debug按钮（虫子图标）开启调试模式。快捷键`Shift+F9`
- `F7` Step Into：单步跳入函数
- `F8` Step Over：单步跳过函数
- `Shift+F8` Step Out：跳出函数
- `F9` Resume：运行到下一个断点
- 下方Debug窗口观察变量值。

底部可查看变量、调用栈，排查bug非常方便

## CLion调试练习代码（C语言）

新建 `main.c`，复制代码，练习**打断点、单步调试、观察变量窗口**

```c
#include <stdio.h>

// 求数组最大值
int get_max(int arr[], int len)
{
    int max = arr[0];
    for (int i = 0; i < len; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main(void)
{
    int nums[] = {12, 44, 7, 99, 23, 56};
    int length = sizeof(nums) / sizeof(nums[0]);

    int max_num = get_max(nums, length);

    printf("数组最大值 = %d\n", max_num);

    return 0;
}
```

### ✅练习任务

1. 在 `if(arr[i] > max)` 行打红色断点
2. Shift+F9 启动调试
3. `F7` 进入函数 get_max
4. `F8` 单步执行，观察 `i`、`arr[i]`、`max` 变量变化
5. `F9` 直接运行到下一次断点
6. `Shift+F8` 跳出函数

> 修改 CMakeLists.txt 之后，记得点右上角 **Reload CMake Project**。

---

# 五、常用设置优化清单

## 1.设置中文界面

File → Settings → Appearance → Plugins  搜索 Chinese 安装中文插件，重启生效

## 2.外观编辑器

`Settings → Appearance & Behavior → Appearance`

- Theme：Darcula深色；勾选`Show line numbers`显示行号；`Show method separators`函数分隔线 `Editor → Font`
- 字体：JetBrains Mono / Consolas；字号14；行间距1.2；开启Font ligatures连字。

## 3.编码设置（解决中文乱码 Windows高频坑）

`Editor → File Encodings`

- Global Encoding：`UTF‑8`
- Project Encoding：`UTF‑8`
- Default encoding for properties files：`UTF‑8`
- 不要勾选 with‑Bom。

> Windows MinGW控制台中文乱码额外操作：
> 快捷键 `Ctrl+Shift+Alt+/` → Registry → 取消勾选 `run.processes.with.pty`，重启CLion。

## 4.代码风格

`Editor → Code Style → C/C++`

- Indent：4空格；自动格式化快捷键 `Ctrl+Alt+L`。

## 5.插件优化，提速

`Plugins`，不需要就禁用：Qt、CUDA、Docker、Database；
保留核心：C/C++、CMake、Git Integration。

## 6.Git忽略模板 .gitignore

```plaintext
.idea/
cmake‑build‑*/
*.cmake
CMakeCache.txt
CMakeFiles/
```

> cmake‑build‑debug 编译产物，不要提交版本库。

## 7.关闭多余提醒：

设置里关掉CMake自动重载的冗余提示。

# 六、高频快捷键 Windows

| 快捷键        | 功能         |
| ---------- | ---------- |
| Ctrl+Alt+S | 打开设置       |
| Ctrl+Alt+L | 格式化代码      |
| Ctrl+/     | 行注释        |
| Shift+F10  | 运行         |
| Shift+F9   | 调试         |
| F7/F8/F9   | 调试单步/跳过/继续 |
| Ctrl+F9    | 构建项目       |
| 双击Shift    | 全局搜索文件     |
| Alt+Enter  | 快速修复提示     |

# 七、新手常见报错排查

1. **运行按钮灰色** 工具链Toolchains配置错误；CMakeLists语法错误；点击Reload CMake Project。
2. **报未定义引用 undefined reference** 新增`.c/.cpp`文件没有写到`add_executable()`里面！90%新手踩坑点。
3. **中文控制台乱码** 文件编码UTF‑8，Registry关闭`run.processes.with.pty`。
4. 头文件红色波浪线找不到
   CMake没有reload；或者头文件路径没有配置。
5. cmake‑build‑debug目录异常
   File → Reload CMake Project；也可以删除cmake‑build‑debug文件夹重新构建。

# 八、简单多文件项目目录示例

```plaintext
demo/
├── CMakeLists.txt
├── main.cpp
├── include/
│   └── calc.h
└── src/
    └── calc.cpp
```

CMakeLists增加头文件目录：

```cmake
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(demo main.cpp src/calc.cpp)
```

如果你需要，我可以给一份CLion的CMakeLists常用模板，或者一套C语言练习代码用来熟悉CLion调试。

# 九、CLion默认项目目录结构

```plaintext
demo/
├── .idea/                # IDE本地配置，不要提交Git，自动生成
├── cmake‑build‑debug/    # CMake编译输出目录，exe、obj文件，自动生成，可删除
├── CMakeLists.txt        # ✅核心构建脚本，CMake配置文件【必须提交Git】
├── main.c / main.cpp     # 源代码
└── .gitignore
```

> ⚠️新手大坑：新增`.c/.cpp`文件，**必须加到CMakeLists.txt的add_executable里面**，否则编译看不见新文件，报未定义引用错误。

# 十、CMakeLists.txt 基础讲解（新手必懂）

> CLion所有项目都靠这个文件管理，默认生成内容（C++最小模板）：

### CMakeLists.txt最小模板（C）

项目结构

```plaintext
demo/
├─ main.c
└─ CMakeLists.txt
```

`CMakeLists.txt`

```cmake
# 指定cmake最低版本要求，CLion默认版本更高，写3.20够用
cmake_minimum_required(VERSION 3.3) 

# 项目名称，语言 C，同时支持C和C++
project(MyFirstProject)

# 设置C标准 C11，不使用编译器扩展
set(CMAKE_C_STANDARD 11) # C标准
set(CMAKE_C_STANDARD_REQUIRED ON) # 强制使用上面的标准，不允许回退旧版本

# 生成可执行文件：项目名 源码文件，关联源文件，新增源文件写在这里
add_executable(MyFirstProject main.cpp) # 后面跟上所有 .c源文件，空格分隔
```

1.新增c文件：只需要在 add_executable 后面追加文件名，例： add_executable(app main.c test.c)

2.修改CMakeLists后**必须Reload CMake + Clean再编译**，旧缓存不会自动更新编译参数。

3.修改CMakeLists之后，CLion会自动Reload CMake Project；没有自动刷新：修改后右键项目 →  Reload CMake Project  生效，或者点击右上角`Reload CMake Project`按钮。

## CMakeLists.txt 模板（MinGW‑Windows，解决CMD中文乱码）

> 适用：CLion + MinGW‑w64，编译出来exe在Windows原生CMD中文不乱码
> 
> 原理： `‑fexec‑charset=GBK`  指定程序运行输出字符集为GBK，匹配CMD默认CP936
> 
> ⚠️ 只对GCC/MinGW有效，MSVC不要加这两行

```cmake
cmake_minimum_required(VERSION 3.25)

# 项目名，改成你自己的
project(DemoProject)

# 设置C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 开启编译警告，方便找bug（推荐加上）
add_compile_options(-Wall -Wextra)

# ========= MinGW Windows CMD中文乱码关键配置 =========
if (MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexec-charset=GBK")
endif()
# ======================================================

# 生成可执行文件：第一个参数是exe名字，后面接你的源文件
add_executable(main
        main.c
        # 其他.c文件在这里追加
        # utils.c
)
```

### 使用步骤

1. 把上面全部复制替换你原来的  `CMakeLists.txt` 

2. CLion右上角： `Reload CMake Project` （重新加载CMake）

3. Clean 清理旧构建产物，再重新 Build

4. 找到cmake-build-debug下生成的 main.exe，双击/在cmd运行，中文输出正常

### 如果你想走 UTF‑8 路线（不修改编译字符集，代码内设置控制台编码）

CMake不需要加GBK那两行，main.c示例：

```cpp
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    std::cout << "测试中文输出 hello 世界 ";
    return 0;
}
```

# 十一、CLion CMake 常用指令清单和模板（新手版）

> 说明：CLion 的项目完全靠  `CMakeLists.txt` ，修改保存后，右键项目 → **Reload CMake Project** 才会生效。
> 
> 环境：CMake 3.16+，适配 Windows(MSVC) / Linux / macOS，提供**最小可运行、多文件项目、库项目**等模板。
> 
> 编译产物默认输出到  `cmake‑build‑debug`  /  `cmake‑build‑release` 。

## 🔧 常用指令分类

1. **版本、项目、语言标准**

```cmake
# 指定cmake最低版本
cmake_minimum_required(VERSION 3.20)

# project(项目名 语言)
project(myapp)

# 设置C语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 开启编译警告，方便找bug（推荐加上）
add_compile_options(-Wall -Wextra)
```

2. **生成程序：可执行文件 / 静态库 / 动态库**

```cmake
# 生成可执行程序（写程序最常用）
add_executable(程序名 源文件1.c 源文件2.c ...)
add_executable(test main.c calc.c)

# 生成静态库 .a / .lib
add_library(mylib STATIC calc.c util.c)

# 生成动态库 .so / .dll
add_library(mylib SHARED calc.c util.c)
```

3. **头文件目录 include 路径**

当头文件不在当前目录，需要告诉cmake去哪里找  `.h` 

```cmake
# 添加头文件搜索目录
target_include_directories(目标名 PUBLIC ./include)

# 示例：可执行程序test去include文件夹找头文件
target_include_directories(test PUBLIC ./include)
```

4. **链接库（把库绑定到程序）**

```cmake
# target_link_libraries(程序名 库名)
# 把自己写的静态库mylib链接给test程序
target_link_libraries(test mylib)

# 链接系统库，例如linux数学库m
target_link_libraries(test m)
```

5. **源文件放在子文件夹**

项目结构：

```plaintext
project/
├─src/
│ main.c
│ util.c
├─include/
│ util.h
└─CMakeLists.txt
```

写法：

```cmake
cmake_minimum_required(VERSION 3.20)
project(demo)
set(CMAKE_C_STANDARD 11)

add_executable(demo
    src/main.c
    src/util.c
)

target_include_directories(demo PUBLIC ./include)
```

6. **递归获取文件夹下全部cpp（不推荐新手滥用）**

新手不建议，新增删除文件不会自动检测，需要手动Reload CMake

```cmake
aux_source_directory(./src SRC_LIST)
add_executable(demo ${SRC_LIST})
```

7. **子项目 add_subdirectory**

当项目分多个模块，每个模块有自己的 CMakeLists.txt 

```cmake
# 进入lib文件夹，读取里面的CMakeLists.txt
add_subdirectory(lib)
```

8. **Debug / Release 模式设置**

CLion右上角可以切换Debug/Release配置

```cmake
# 设置debug模式编译选项
set(CMAKE_C_FLAGS_DEBUG "-g -O0")

# release开启优化
set(CMAKE_C_FLAGS_RELEASE "-O2")
```

9. **输出路径修改（把exe输出到指定文件夹）**

```cmake
# 可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 库文件输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
```

## 📦 常见项目示例模板

### 模板1：最小单文件可执行程序

项目结构

```plaintext
DemoProject/
├─ main.cpp
└─ CMakeLists.txt
```

`CMakeLists.txt`

```cmake
# 指定cmake最低版本要求
cmake_minimum_required(VERSION 3.16)

# 项目名称，语言 C / CXX(C++)
project(DemoProject LANGUAGES C CXX)

# 设置C++标准 C++17，不使用编译器扩展
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 生成可执行文件：项目名 源码文件
add_executable(DemoApp main.cpp)
```

构建命令（终端）

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

---

### 模板2：简单多文件项目

目录

```plaintext
multi_demo/
├─main.c
├─foo.c
├─foo.h
└─CMakeLists.txt
```

**CMakeLists.txt**

```cmake
cmake_minimum_required(VERSION 3.20)
project(multi_demo)
set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

add_executable(multi_demo
    main.cpp
    foo.cpp
)
```

### 模板3：多文件C项目（带include头文件目录）

`CMakeLists.txt`

目录结构

```plaintext
demo_c/
├── CMakeLists.txt
├── main.c
├── include
│   └── calc.h
└── src
    └── calc.c
```

CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.20)
project(demo_c LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)

# 指定头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 收集所有cpp源码
file(GLOB SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
# 把所有c源码全部写在这里
add_executable(demo_c
        main.c
        s${SRC_FILES})
```

> 注意：`file(GLOB)` 适合小项目；大型项目建议手动列出源文件，避免新增文件不触发重编译。

---

### 模板4：使用静态库 + 可执行程序（最常用工程模板）

目录结构

```plaintext
lib_demo/
├─ main.c
├─ CMakeLists.txt
├─ src/
│  └─ libcalc_lib.c
└─ include/
   └─ libcalc.h
```

`CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.20)
project(lib_demo)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)

# 1.编译静态库
add_library(calc STATIC src/libcalc.c)
target_include_directories(calc PUBLIC ./)

# 2.编译主程序
add_executable(app main.c)

# 3.主程序链接静态库
target_link_libraries(app PRIVATE calc) # 链接静态库
```

- `STATIC`：静态库 `.lib`(win) / `.a`(linux)
- `SHARED`：动态库 `.dll`(win) / `.so`(linux) / `.dylib`(mac)
- `PRIVATE / PUBLIC / INTERFACE` 链接权限：
  - `PRIVATE`：仅当前目标使用
  - `PUBLIC`：当前目标 + 依赖它的目标都生效

### 模板5：Windows MSVC 额外配置（中文乱码、输出目录）

```cmake
cmake_minimum_required(VERSION 3.16)
project(MsvcDemo)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# MSVC编译器配置
if(MSVC)
    add_compile_options(/utf‑8)       # 源码和执行文件UTF‑8，解决中文乱码
    add_compile_options(/W4)          # 开启警告等级4
    add_compile_options(/WX‑)         # 警告不视为错误
endif()

# 设置输出目录：所有exe、dll输出到bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(App main.cpp)
```

### 模板6：子目录多模块项目（add_subdirectory）

目录

```plaintext
bigproj/
├─ CMakeLists.txt
├─ main.cpp
└─ module_a/
   ├─ CMakeLists.txt
   ├─ a.cpp
   └─ a.h
```

根目录 `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.16)
project(BigProj LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

# 引入子模块
add_subdirectory(module_a)

add_executable(BigApp main.cpp)
target_link_libraries(BigApp PRIVATE module_a_lib)
```

`module_a/CMakeLists.txt`

```cmake
add_library(module_a_lib STATIC a.cpp)
target_include_directories(module_a_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

---

### 模板7：简单Git忽略文件 .gitignore

```gitignore
# CLion IDE配置
.idea/

# CMake编译产物
cmake-build-*/
CMakeCache.txt
CMakeFiles/
*.cmake
install_manifest.txt

# 操作系统
.DS_Store
Thumbs.db
```

### ⚠️ 新手高频踩坑

**1. 新增c文件一定要写到add_executable的文件列表中！**

不写进去CLion识别不到，编译直接报未定义引用。

2. 修改完CMakeLists.txt，**必须Reload CMake Project，否则不生效**。

3. 头文件  `.h`  不需要写进  `add_executable` ，只需要 `target_include_directories` 指定目录即可。

4. 报错乱码：`CLion设置 → Editor → File Encodings`，全部设为UTF‑8。

5. CMake报错时，可以删除  `cmake‑build‑debug`  整个文件夹，重新加载。

### 📝 常用变量速查表

| 变量                    | 含义                        |
| --------------------- | ------------------------- |
| ${CMAKE_SOURCE_DIR}   | 项目根目录                     |
| ${CMAKE_BINARY_DIR}   | 编译输出目录（cmake‑build‑debug） |
| PROJECT_NAME  project | 设置的项目名                    |

### 关键常用指令速查表

| 命令                             | 作用                                   |
| ------------------------------ | ------------------------------------ |
| `cmake_minimum_required()`     | 最低CMake版本                            |
| `project()`                    | 定义项目名、语言                             |
| `set()`                        | 设置变量                                 |
| `add_executable()`             | 生成可执行文件                              |
| `add_library()`                | 生成静态/动态库                             |
| `target_include_directories()` | 给目标设置头文件路径（推荐，替代include_directories） |
| `target_link_libraries()`      | 目标链接库                                |
| `add_subdirectory()`           | 引入子文件夹CMake项目                        |
| `if(MSVC)`                     | Windows MSVC条件判断                     |
| `if(UNIX)`                     | Linux/macOS条件判断                      |

> 💡最佳实践：优先使用 `target_xxx` 系列命令（target_include_directories），不要全局 `include_directories`，作用域清晰，适合大型项目。

### 配套习题

1. 使用模板1新建项目，编译输出 `cout<<"Hello CMake"`。
2. 修改模板3，把静态库改为**动态库(SHARED)**，编译运行观察dll文件生成。
3. 使用模板4，验证MSVC下中文输出不乱码。
4. 搭建子目录项目结构，使用`add_subdirectory`拆分模块。

如果你需要，我可以给一份**可直接复制的CMake完整工程目录模板**，或者 CMakeLists.txt 调试技巧。

# 十二、✨ CLion中修改选项两种方式

## 方式1：直接改CMakeLists.txt

```cmake
option(BUILD_MY_LIB "build internal static library" OFF)
option(ENABLE_LOG "enable log print" OFF)
```

改完后右键项目 →  `Reload CMake Project` 

## 方式2：CLion图形界面修改

 `File → Settings → Build,Execution,Deployment → CMake` 

找到  `CMake options` ，填入：

```plaintext
-DBUILD_MY_LIB=ON -DENABLE_LOG=OFF
```

## ⚠️ 使用注意

1. CLion右上角切换  `Debug / Release`  配置，切换后需要`Reload CMake`。

2. 宏  `add_definitions(-DXXX)`  等价于代码里 `#define XXX` 。

3. 如果不需要内部库，直接把 `BUILD_MY_LIB` 设为 OFF ，库就不会编译、也不会链接。

4. 清理构建：删除 `cmake‑build‑debug` 、 `cmake‑build‑release` 文件夹，重新加载。

## 常用扩展小提示

- 链接线程库： `target_link_libraries(${PROJECT_NAME} pthread)` （Linux）

- 如果你不需要C++语言，把 `project(my_app C CXX) 改为 project(my_app)` 。

# 十二、CMake 简单排错清单（CLion场景）

> 出现CMake报错，优先顺序：看CLion底部CMake输出日志 → 按下面逐条排查 → 不行就删除构建目录重新Reload。

## 🔴 第一类：CMake解析报错（CMakeLists.txt语法错误）

现象：CLion提示  CMake Error at CMakeLists.txt:xx ，指向某一行。

1. 括号、引号必须成对， add_executable(  少右括号、逗号多写漏写都会报错。

2. 指令大小写不敏感，但变量名区分大小写。

3. 换行：源文件列表一行一个，不要漏换行； # 是注释，后面内容全部忽略。

4. 字符串路径带空格，一定要用双引号包裹  "${CMAKE_SOURCE_DIR}/my project" 。

✅修复：定位报错行，检查语法；修改后 Reload CMake Project。

## 🟠 第二类：工具链/编译器问题

现象：报错  no CMAKE_CXX_COMPILER could be found 、找不到gcc/g++。

1. Windows：检查 Toolchains 是否选中MinGW，gcc/g++是否真实存在。

2. macOS：确认执行过  xcode-select --install 。

3. Linux：确认安装  gcc g++ cmake gdb 。

4. CLion： File→Settings→Build,Execution,Deployment→Toolchains ，看是否有红色警告。

✅修复：配置好编译器；如果工具链显示红色，重新选择gcc路径。

## 🟡 第三类：找不到头文件  fatal error: xxx.h: No such file or directory

编译报错找不到 .h 头文件。

1. 是否写了  target_include_directories(目标 PUBLIC 头文件目录) 。

2. 路径写错：区分相对路径，多用  ${CMAKE_SOURCE_DIR}  写绝对项目根路径。

3. ⚠️不要用  include_directories()  全局乱加，优先用target_include_directories。

4. 修改CMakeLists之后必须Reload CMake。

✅修复：核对include目录路径；Reload。

## 🟢 第四类：未定义引用 undefined reference（高频大坑）

编译能过，链接阶段报错，函数声明找到了，但找不到函数实现。

原因：

1.  .cpp/.c 源文件没有加到add_executable / add_library源文件列表。（最常见！头文件h不需要写，cpp一定要写）

2. 库没有链接，忘记写 target_link_libraries() 。

3. C和C++混编extern"C"问题。

4. 库顺序错误：被依赖的库要写在后面。

✅修复：

- 把所有实现文件加入add_executable；

- 确认链接库指令；

- 保存后Reload CMake。

## 🔵 第五类：新增文件后CLion识别不到

现象：新建c文件，CLion看不见，编译报函数找不到。

1. 新 .c 必须手动加到 add_executable 的文件列表。

2. 不要过度依赖 aux_source_directory ，新增文件不会自动更新。

3. 修改CMakeLists之后右键项目 Reload CMake Project。

## 🟣 第六类：Debug/Release 行为异常，改配置不生效

1. CLion右上角切换Debug/Release，切换之后建议Reload CMake。

2. option选项修改后，必须Reload。

3. 条件编译宏不生效：确认 add_definitions(-DXXX) 写对，区分大小写。

## ⚫ 万能急救操作（80%诡异问题可以解决）

1. 关闭CLion。

2. 删除项目目录下： cmake‑build‑debug 、 cmake‑build‑release  两个文件夹。

3. 重新打开CLion，等待CMake自动重新加载。

## 🟤 第七类：中文乱码

Windows平台控制台输出中文乱码：

1. Settings → Editor → File Encodings，全部设置为UTF‑8。

2. 如果是MinGW，可添加编译选项： add_compile_options(-fexec-charset=UTF-8) 

## 📋快速自查小表，出问题照着勾一遍

CMakeLists.txt语法无括号缺失

Toolchain编译器无红色报错

全部 .c 实现文件加入add_executable

头文件目录通过target_include_directories配置

需要链接的库写target_link_libraries

修改CMakeLists后执行Reload CMake Project

异常时删除cmake‑build‑*构建目录重新生成

## 💡排错小技巧

1. 使用 `message(STATUS "打印信息: ${变量名}")` 打印变量，查看路径是否符合预期。

```cmake
message(STATUS "项目根目录: ${CMAKE_SOURCE_DIR}")
```

2. 仔细阅读CMake输出窗口的完整报错，**第一行报错才是真正原因**，后面都是连锁报错。

# 十三、常见新手坑

1. 运行报错：工具链没配置好，回到Settings检查Toolchain的gcc/g++路径

2. 多个c文件报错：没有全部加到 add_executable 里

3. 中文乱码：Settings → Editor → File Encodings 全部改为UTF-8

4. CMake报错：删除cmake-build-debug文件夹，重新加载CMake

> CLion内置控制台不乱码、原生cmd乱码，本质就是系统控制台编码和编译器输出编码不匹配。

# 十五 、中文乱码核心原因

Windows CMD默认编码是**GBK(CP936)**，CLion默认源码/编译器输出是**UTF-8**，编码不匹配导致exe运行时中文乱码，下面给4种可直接落地的方案，优先选前2种。

## 方案1：编译时指定输出为GBK（最省事，直接兼容原生CMD）

在项目的 CMakeLists.txt 最顶部添加编译参数，强制MinGW编译器输出GBK编码：

```cmake
# MinGW专用，适配Windows CMD GBK编码
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexec-charset=GBK")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=GBK")
```

修改后**重新加载CMake、重新编译**，生成的exe直接在cmd运行中文正常。

## 方案2：代码里强制CMD切换UTF-8编码（跨平台兼容好）

C/C++代码开头引入Windows头文件，运行时设置控制台编码为UTF-8：

```cpp
#include <windows.h>
#include <iostream>
using namespace std;

int main() {
    // 设置控制台输出、输入编码为UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    cout << "中文测试" << endl;
    return 0;
}
```

**缺点**：仅Windows生效，Linux/macOS需要屏蔽这段代码。

## 方案3：临时/永久修改CMD编码为UTF-8

### 1. 临时生效（每次打开cmd执行）

打开cmd，输入：

```cmd
chcp 65001
```

再运行exe，中文正常；关闭cmd后失效。

### 2. 永久生效（注册表）

Win+R输入 regedit ，定位：

```plaintext
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Command Processor
```

新建字符串值 `autorun ，数值填 `chcp 65001` ，重启cmd永久默认UTF-8。

## 方案4：CLion全局统一改为GBK编码

1. 打开 `Settings → Editor → File Encodings` 

- 全局编码、项目编码都改为 `GBK`

- 单个cpp文件右下角编码也切换为`GBK`

2. 配合方案1的CMake参数，彻底适配Windows原生控制台。

## 补充避坑

- 不要勾选Windows「Beta版：使用Unicode UTF-8提供全球语言支持」，会导致部分老软件异常；

- CLion内置控制台不乱码、原生cmd乱码，本质就是系统控制台编码和编译器输出编码不匹配，优先用**方案1**一劳永逸。

## 常见踩坑提醒

1. 如果用**MSVC编译器**， `‑fexec‑charset=GBK`  参数无效，会报错，模板里用 `if(MINGW)` 做了判断，MSVC环境会自动跳过。 

2. CLion内置终端本身用UTF‑8，用这套GBK参数，**CLion内置控制台中文会乱码**，这是取舍：

- 想要原生cmd正常：用上面模板（内置终端乱码）

- 想要内置终端和cmd都正常：用第二种，代码里 `SetConsoleOutputCP(65001)` 的UTF‑8方案。

# 十六、CLion新手自检小清单

- 项目路径**无中文、无空格**
- Toolchains工具链MinGW‑w64配置正常，gcc/g++/gdb全部识别
- 新增`.c/.cpp`必须写入`add_executable()`
- 头文件目录使用 `include_directories()`
- 编码全部设置为UTF‑8，Windows控制台乱码关闭 `run.processes.with.pty`
- cmake‑build‑debug 编译产物不要提交Git

接下来可以：

1. 练习多文件头文件拆分代码
2. 或者我给你一份CLion优化设置清单，你想要哪个？

# 十七、CLion 项目上传 GitHub 图形化操作（C/C++ / C#）

> 前置准备
> 
> 1. CLion 内置开启 Git，安装 GitHub 插件（默认自带）
> 2. 项目根目录已经放好 `.gitignore`、`README.md`
> 3. CLion登录GitHub账号：`文件 → 设置 → 版本控制 → GitHub`，网页授权登录
> 4. 打开CLion项目（CMakeLists.txt所在项目）

## 方式一：本地项目直接在CLion一键发布到GitHub（推荐新手）

1. 顶部菜单：`VCS → 导入到版本控制 → Share Project on GitHub`（共享项目到GitHub）
2. 如果还没登录GitHub，会弹出浏览器授权登录
3. 在弹窗填写：
   - Repository name：仓库名称
   - Description：项目描述
   - ✅ Private：勾选=私有仓库，不勾选=公开仓库
   - Remote名称默认 `origin`，不要修改
4. 点击【Share】
5. CLion自动：初始化本地Git仓库 + GitHub网页创建仓库 + 提交并推送全部代码
6. 推送成功后事件日志会出现链接，可以直接跳转GitHub仓库页面

## 方式二：GitHub网页先新建空仓库，本地CLion项目关联远程

1. GitHub网页新建空仓库，**不要勾选Add README**，复制仓库HTTPS地址
2. CLion顶部菜单 `VCS → 启用版本控制集成`，选择Git，初始化本地仓库
3. 左侧打开【Commit提交窗口】快捷键 `Alt+0`
   - Unversioned Files：未跟踪文件
   - 勾选需要提交的源码文件（**不要勾选 .idea、cmake-build-debug**，.gitignore已经过滤）
4. 在下方输入提交信息：`init:项目初始化`
5. 点击【Commit】提交到本地仓库
6. 顶部菜单 `Git → 管理远程仓库 → 添加`，名称填`origin`，粘贴GitHub仓库地址
7. 顶部菜单 `Git → Push`（快捷键 `Ctrl+Shift+K`），弹出推送窗口，点击Push上传代码

## ✅ 日常修改代码，图形化提交推送（最常用流程）

1. 修改代码，保存文件
2. 打开左侧Commit面板 `Alt+0`
3. 勾选变更文件，填写提交备注（例：`feat:新增查询功能`）
4. 两个选项：
   - Commit：仅提交本地仓库
   - Commit and Push：提交本地并且直接推送到GitHub（一步到位）
5. 如需单独推送：菜单 `Git → Push`，快捷键`Ctrl+Shift+K`

## 📥 拉取远程代码（多人协作）

菜单 `Git → Pull`，拉取GitHub最新代码到本地

## 🌿 分支图形化操作

1. 右下角状态栏VCS小部件（显示当前分支名称），点击分支名
2. New Branch：创建新分支，输入分支名，自动切换
3. 在新分支写代码，提交推送
4. 切回main分支，右下角分支菜单选择`Merge into Current`，选择需要合并的分支
5. 出现冲突：CLion可视化合并窗口，可选【接受当前】【接受传入】【保留两者】，解决冲突后完成合并提交

## ⚠️ CLion专属避坑清单

1. 提交前检查文件列表：`.idea/`、`cmake-build-debug/`、`*.exe` 不应该出现在待提交列表，说明`.gitignore`生效
2. 首次推送报错（远程仓库自带README）：先执行Git → Pull拉取，解决冲突后再Push
3. 找不到Share Project on GitHub：确认GitHub插件启用，CLion已经登录GitHub账号
4. Commit面板看不到文件：确认VCS版本控制集成已经启用

## 常用快捷键

- `Alt+0`：打开Commit提交面板
- `Alt+9`：Git日志面板，查看所有提交记录
- `Ctrl+Shift+K`：Push推送
- `Ctrl+T`：Pull拉取

# 十八、CLion项目上传 GitHub 完整 Git 命令清单

> 适用：CLion C/C++ / C# 项目，根目录已有 `.gitignore` + `README.md` 执行位置：CLion内置终端 / Git Bash，cd 进入**项目根目录（CMakeLists.txt所在目录）**

## 一、首次上传新项目（仅执行一次）

```bash
# 1. 进入项目根目录，替换为你本地项目路径
cd D:/code/CLionProject

# 2. 初始化本地Git仓库
git init

# 3. 检查文件状态，确认cmake-build-debug、.idea等被.gitignore过滤
git status

# 4. 添加所有源码到暂存区
git add .

# 5. 提交到本地仓库，填写提交备注
git commit -m "init: CLion项目初始化，提交基础源码"

# 6. GitHub网页新建空仓库，复制仓库HTTPS地址，关联远程origin
git remote add origin [https://github.com/](https://github.com/)你的用户名/仓库名.git

# （可选）校验远程仓库是否绑定成功
git remote -v

# 7. 首次推送到远程main分支
git push -u origin main
```

## 二、日常迭代提交（修改代码后重复使用）

```bash
# 查看文件改动
git status

# 添加所有变更文件
git add .

# 本地提交，修改备注
git commit -m "feat: 新增学生查询功能"

# 推送到远程GitHub
git push
```

## 三、拉取远程代码（多人协作，同步远程最新代码到本地）

```bash
git pull origin main
```

## 四、分支管理常用命令

```bash
# 查看本地分支
git branch

# 创建新分支dev
git branch dev

# 切换到dev分支
git checkout dev

# 创建并直接切换到新分支（简写）
git checkout -b dev

# 将dev分支推送到远程仓库
git push origin dev

# 合并dev分支到main分支（先切回main）
git checkout main
git merge dev
```

## 五、查看提交日志

```bash
# 完整日志
git log

# 简洁单行日志
git log --oneline
```

## 六、撤销操作（救急命令）

```bash
# git add后，撤销暂存，文件保留
git reset HEAD .

# 撤销最近一次commit，保留代码
git reset --soft HEAD~1

# 丢弃所有未保存的本地修改（谨慎！会删除改动）
git checkout -- .
```

## 七、首次推送冲突处理（远程仓库自带README.md）

```bash
git pull origin main --allow-unrelated-histories
# 手动解决冲突后，再执行
git push
```

## ✅ Commit提交信息规范

- `init:` 项目初始化
- `feat:` 新增功能
- `fix:` 修复bug
- `refactor:` 代码重构
- `chore:` 修改配置、CMakeLists、文档、gitignore

## 📌 CLion项目专属注意事项

1. 不要提交 `.idea/`、`cmake-build-debug/`、`cmake-build-release/`，`.gitignore`已配置忽略
2. CLion自带Git图形界面，命令行和图形界面可以混用
3. 执行`git status`提交前检查，确认编译产物不出现
4. 克隆别人CLion项目后：打开文件夹，CLion会自动加载CMake

> 补充：CLion图形Git入口：顶部菜单 `Git`，可以可视化提交、推送、分支、解决冲突