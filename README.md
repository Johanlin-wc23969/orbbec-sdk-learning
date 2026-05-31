# 8周成为Orbbec SDK工程师
**目标不是"学很多东西"，而是8月入职时达到：**

✅ 看懂Orbbec SDK主要架构
✅ 能独立写现代C++17/20代码
✅ 熟悉Linux/CMake/Git开发流程
✅ 具备OpenCV与深度视觉基础
✅ 拥有1个完整SDK项目放GitHub
✅ 拥有完整技术笔记

---

# Notion总目标

```text
最终成果：

□ 完成 Effective Modern C++
□ 完成 Orbbec SDK源码阅读
□ 完成 Fake Camera SDK项目
□ 完成 OpenCV Vision Toolkit
□ 完成 Linux/CMake学习
□ 完成深度相机知识体系
□ 完成GitHub项目整理
□ 完成技术博客10篇以上
```

---

# 每日固定时间安排

每天5小时

```text
09:00-11:00
现代C++（固定）

11:00-11:15
休息

11:15-12:45
主任务

12:45-13:00
学习总结
```

每天结束必须记录：

```text
今天学了什么：

遇到什么问题：

明天计划：

Git提交：
```

---

# 第一阶段

# Week 1

目标：

建立现代C++基础

搭建开发环境

---

## Day 1

### C++（2h）

```text
auto
nullptr
range-based for
using
```

练习：

```cpp
auto
decltype
```

---

### 主任务（3h）

安装：

```bash
Homebrew
CMake
Ninja
OpenCV
```

验证：

```bash
cmake --version
opencv_version
```

任务：

```text
创建SDK学习仓库
建立Notion知识库
```

---

## Day 2

### C++

```text
Lambda
Capture
Function Object
```

练习：

```cpp
sort
find_if
for_each
```

---

### 主任务

学习：

```text
Git基础
```

练习：

```bash
git init
git commit
git branch
git merge
```

---

## Day 3

### C++

```text
unique_ptr
shared_ptr
weak_ptr
```

---

### 主任务

下载：

[Orbbec SDK v2](https://github.com/orbbec/OrbbecSDK_v2?utm_source=chatgpt.com)

完成：

```text
源码编译
Samples运行
```

---

## Day 4

### C++

```text
Move Semantics
Rvalue Reference
```

---

### 主任务

阅读：

```text
SDK目录结构
```

记录：

```text
Device
Pipeline
Frame
Config
```

关系图

---

## Day 5

### C++

```text
Perfect Forwarding
emplace_back
```

---

### 主任务

阅读：

```text
Pipeline模块
```

输出：

```text
Pipeline工作流程图
```

---

## Day 6

### C++

练习题

---

### 主任务

学习：

```text
OpenCV基础
```

实现：

```cpp
图片读取
视频读取
显示
```

---

## Day 7

### 周总结

复习全部内容

输出：

```text
Week1总结博客
```

---

# Week 2

目标：

C++17核心特性

理解SDK核心模块

---

## Day 8

### C++

```text
Structured Binding
```

---

### 主任务

阅读：

```text
Frame模块
```

记录：

```text
Frame生命周期
```

---

## Day 9

### C++

```text
std::optional
```

---

### 主任务

OpenCV：

```cpp
灰度化
```

---

## Day 10

### C++

```text
std::variant
```

---

### 主任务

阅读：

```text
Sensor模块
```

---

## Day 11

### C++

```text
filesystem
```

---

### 主任务

Linux：

```bash
find
grep
sed
awk
```

---

## Day 12

### C++

```text
constexpr
```

---

### 主任务

OpenCV：

```cpp
Gaussian Blur
```

---

## Day 13

### C++

练习

---

### 主任务

阅读：

```text
Filter模块
```

---

## Day 14

周总结

输出：

```text
Orbbec SDK架构图V1
```

---

# Week 3

目标

多线程

Fake Camera SDK启动

---

## Day 15

### C++

```text
thread
```

---

### 主任务

创建项目：

```text
FakeCameraSDK
```

目录结构设计

---

## Day 16

### C++

```text
mutex
```

---

### 主任务

实现：

```cpp
Device
```

---

## Day 17

### C++

```text
lock_guard
```

---

### 主任务

实现：

```cpp
Frame
```

---

## Day 18

### C++

```text
condition_variable
```

---

### 主任务

实现：

```cpp
Pipeline
```

---

## Day 19

### C++

```text
future
async
```

---

### 主任务

实现：

```cpp
Frame Queue
```

---

## Day 20

### C++

练习

---

### 主任务

实现：

```cpp
Fake Camera Stream
```

---

## Day 21

周总结

完成：

```text
FakeCameraSDK V0.1
```

上传GitHub

---

# Week 4

目标

OpenCV核心

---

Day22-28：

每天：

### C++

继续：

```text
Effective Modern C++
```

---

### 主任务

依次完成：

```text
Day22 边缘检测
Day23 轮廓检测
Day24 特征点检测
Day25 视频处理
Day26 ROI
Day27 图像增强
Day28 整体复习
```

完成：

```text
Vision Toolkit V1
```

---

# Week 5

目标

深度相机知识

---

每天：

### C++

```text
C++20
Concepts
Ranges
```

---

### 主任务

Day29

```text
深度相机原理
```

Day30

```text
双目视觉
```

Day31

```text
ToF
```

Day32

```text
结构光
```

Day33

```text
点云基础
```

Day34

```text
相机标定
```

Day35

```text
深度图处理
```

---

# Week 6

目标

高级工程能力

---

学习：

```text
CMake
```

每天完成：

```text
Day36 Library
Day37 Install
Day38 Export
Day39 Package
Day40 Unit Test
Day41 Benchmark
Day42 Review
```

---

# Week 7

目标

模拟奥比中光开发

---

完善：

```text
FakeCameraSDK
```

新增：

```cpp
Filter
Config
Logger
```

学习：

spdlog

阅读：

fmt

源码

---

# Week 8

目标

入职冲刺

---

Day50-56

每天：

```text
LeetCode 1题

阅读Orbbec源码1小时

项目优化2小时

总结1小时
```

---

最终交付物

```text
GitHub：

□ FakeCameraSDK
□ VisionToolkit

笔记：

□ C++笔记
□ Linux笔记
□ OpenCV笔记
□ 深度相机笔记
□ Orbbec SDK架构分析

博客：

□ 10篇以上

源码阅读：

□ Device
□ Pipeline
□ Frame
□ Sensor
□ Filter
```

如果严格执行这份计划，到入职时，你的水平大概率会超过大部分刚毕业的SDK工程师，并且能在入职后的1-2个月内快速进入产出状态。
