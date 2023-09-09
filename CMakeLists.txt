cmake_minimum_required(VERSION 3.25)
PROJECT(STL CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Chapter 1
add_executable(new_feature_1
        Chapter1/使用结构化绑定来解包绑定的返回值.cpp)
add_executable(new_feature_2
        Chapter1/讲变量作用于限制于if和switch区域内.cpp)
add_executable(new_feature_3
        Chapter1/新的括号初始化规则.cpp)

## 一些些补充的小知识
add_executable(struct_constructor
        Chapter1/结构体构造函数.cpp)
add_executable(new_feature_4
        Chapter1/可变参数模板.cpp)
## END

add_executable(new_feature_5
        Chapter1/使用constexpr-if简化编译.cpp
        Chapter1/header/aux_5.h
)
add_executable(new_feature_6
        Chapter1/使用折叠表达式实现辅助函数.cpp)

# Chapter 2