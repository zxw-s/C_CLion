

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

# CLion 项目上传 GitHub 图形化操作（C/C++ / C#）

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

# CLion项目上传 GitHub 完整 Git 命令清单

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