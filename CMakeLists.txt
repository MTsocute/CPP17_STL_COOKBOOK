cmake_minimum_required(VERSION 3.25)
PROJECT(STL CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Chapter 1
#add_executable(new_feature_1
#        Chapter1/使用结构化绑定来解包绑定的返回值.cpp)
#add_executable(new_feature_2
#        Chapter1/讲变量作用于限制于if和switch区域内.cpp)
#add_executable(new_feature_3
#        Chapter1/新的括号初始化规则.cpp)
#
### 一些些补充的小知识
#add_executable(struct_constructor
#        Chapter1/结构体构造函数.cpp)
#add_executable(new_feature_4
#        Chapter1/可变参数模板.cpp)
### END
#
#add_executable(new_feature_5
#        Chapter1/使用constexpr-if简化编译.cpp
#        Chapter1/header/aux_5.h
#)
#add_executable(new_feature_6
#        Chapter1/使用折叠表达式实现辅助函数.cpp)

# Chapter 2
#add_executable(STL_Vector
#        Chapter2/vectorSTL操作.cpp
#        Chapter2/vectorSTL操作.h)
#add_executable(STL_Map
#        Chapter2/mapSTL操作.cpp
#        Chapter2/mapSTLOP.cpp)
#target_link_directories(STL_Map PUBLIC
#        Chapter2/mapSTL操作.h)
#add_executable(STL_set
#        Chapter2/setSTL操作.cpp
#        Chapter2/setSTL操作.h)
#add_executable(RPN
#        Chapter2/逆波兰计算器.cpp
#        Chapter2/逆波兰计算器.h)
#add_executable(Map_in_use
#        Chapter2/词频计数器.cpp
#        Chapter2/词频计数器.h)
#add_executable(STL_priority_queue
#        Chapter2/priority_queue.cpp
#        Chapter2/priority_queue.h)

# Chapter 3
#add_executable(own_iterator
#        Chapter3/实现一个简单的迭代器.cpp
#        Chapter3/实现一个简单的迭代器.h)
#add_executable(iterator_wrapper
#        Chapter3/迭代适配器.cpp)
#add_executable(iterator_algorithm
#        Chapter3/迭代器算法.cpp
#        Chapter3/迭代器算法.h)
#add_executable(reverse_iterator
#        Chapter3/反向迭代器.cpp
#        Chapter3/反向迭代器.h)
#add_executable(it_sentinel
#        Chapter3/哨兵模式.cpp
#        Chapter3/哨兵模式.h)

# Chapter 4
#add_executable(lambda_func
#        Chapter4/lambda函数.cpp)
#add_executable(function_wrapper
#        Chapter4/补充知识/function_func_wrapper.cpp
#        Chapter4/补充知识/function_func_wrapper.h)
#add_executable(lambda_func_with_func_wrapper
#        Chapter4/使用lambda为function添加多态性.cpp
#        Chapter4/使用lambda为function添加多态性.h)
## 把需要使用的函数嵌套在一起，成为一个新的函数（不限制数量）
#add_executable(concatenation_func
#        Chapter4/并置函数.cpp)
#add_executable(combine
#        Chapter4/通过逻辑连接创建复杂谓词.cpp
#        Chapter4/通过逻辑连接创建复杂谓词.h)
#add_executable(multicaller
#        Chapter4/同一输入调用多个函数.cpp)

# Chapter 5
add_executable(STL_Copy
        Chapter5/容器间的互相拷贝.cpp
        Chapter5/容器间的互相拷贝.h)
add_executable(STL_Sort Chapter5/容器元素的排序.cpp)
add_executable(STL_Remove Chapter5/从容器中删除指定元素.cpp)