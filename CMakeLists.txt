cmake_minimum_required(VERSION 3.25)
PROJECT(STL CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Third Part Library
find_package(range-v3 REQUIRED)
find_package(fmt REQUIRED)

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
#        Chapter4/并置函数.cpp
#        Chapter8/module_test/zip_func.cpp)
#add_executable(combine
#        Chapter4/通过逻辑连接创建复杂谓词.cpp
#        Chapter4/通过逻辑连接创建复杂谓词.h)
#add_executable(multicaller
#        Chapter4/同一输入调用多个函数.cpp)

# Chapter 5
#add_executable(STL_Copy
#        Chapter5/容器间的互相拷贝.cpp
#        Chapter5/容器间的互相拷贝.h)
#add_executable(STL_Sort Chapter5/容器元素的排序.cpp)
#add_executable(STL_Remove Chapter5/从容器中删除指定元素.cpp)
#add_executable(STL_Transform
#        Chapter5/改变容器内容.cpp)
### 补充知识
#add_executable(stringStream
#        Chapter5/补充知识/stringstream的使用.cpp)
### --------
#
#add_executable(STL_Search
#        Chapter5/在有序和无序的vector中查找元素.cpp
#        Chapter5/在有序和无序的vector中查找元素.h)
#add_executable(STL_Locate_Range
#        Chapter5/在vector中的值控制在特定范围内.cpp
#        Chapter5/在vector中的值控制在特定范围内.h)
#add_executable(STL_string_Search
#        Chapter5/字符串中的定位方法.cpp)
#add_executable(STL_Sampling
#        Chapter5/对大vector采样.cpp)
#add_executable(STL_Merge
#        Chapter5/合并容器.cpp)

# Chapter 6
#add_executable(STL_Research_Tree
#        Chapter6/使用STL算法实现简单单词查找树.cpp
#        Chapter6/使用STL算法实现简单单词查找树.h)

# Chapter 7
#add_executable(string_view_recognize
#        Chapter7/创建and连接and转换字符串.cpp)
#add_executable(eliminate_space
#        Chapter7/消除字符串开头和结尾的空格.cpp)
#add_executable(string_view_feature
#        Chapter7/无需构造string.cpp)
#add_executable(get_user_s_data
#        Chapter7/从用户输入读取数值.cpp)
#add_executable(count_all_word
#        Chapter7/计算文件中的单词数量.cpp)
#add_executable(file_initiates_complex_obj
#        Chapter7/文件初始化复杂对象.cpp)
#add_executable(filling_container
#        Chapter7/迭代器装填容器.cpp)
#add_executable(ostream_printing
#        Chapter7/迭代器打印.cpp)
#add_executable(log_to_file
#        Chapter7/输出数据到文件.cpp)
#add_executable(readable_error_msg
#        Chapter7/从错误中获取可读异常.cpp)
#target_link_libraries(readable_error_msg PRIVATE fmt)

# Chapter8
#add_executable(STL_TIME_ABOUT
#        Chapter8/转换不同的时间单位.cpp)
#target_link_libraries(STL_TIME_ABOUT PUBLIC fmt)
#add_executable(STL_TIME_ABOUT2
#        Chapter8/转换绝对时间和相对时间.cpp)
#target_link_libraries(STL_TIME_ABOUT2 PUBLIC fmt)
#add_executable(optional
#        Chapter8/安全的失败标识--optional.cpp
#        Chapter8/optional_head.h)
#target_link_libraries(optional PRIVATE fmt)
#add_executable(func_to_tuple
#        Chapter8/对元组使用函数.cpp
#        Chapter8/对元组使用函数.h)
#target_link_libraries(func_to_tuple PRIVATE fmt)
#add_executable(tuple_DS
#        Chapter8/元组快速构成数据结构.cpp
#        Chapter8/元组快速构成数据结构.h)
#target_link_libraries(tuple_DS fmt::fmt)
#target_link_libraries(tuple_DS range-v3::range-v3)
#add_executable(any_substitute_void
#        Chapter8/any的替换void*.cpp)
#target_link_libraries(any_substitute_void fmt::fmt)
#add_executable(variant
#        Chapter8/存储不同类型.cpp
#        Chapter8/存储不同类型.h)
#target_link_libraries(variant fmt::fmt)
#add_executable(unique_pointer_in_use
#        Chapter8/自动规划资源管理.cpp
#        Chapter8/自动化规划资源管理.h)
#add_executable(shared_pointer
#        Chapter8/处理共享堆内存.cpp
#        Chapter8/处理共享堆内存.h)
#add_executable(weak_pointer
#        Chapter8/对共享对象使用弱指针.cpp
#        Chapter8/对共享对象使用弱指针.h)
#target_link_libraries(weak_pointer fmt::fmt)
#add_executable(smartP_with_API
#        Chapter8/智能指针简化处理遗留API问题.cpp
#        Chapter8/智能指针简化处理遗留API问题.h)
#add_executable(shared_P_different_member
#        Chapter8/共享同一对象的不同成员.cpp
#        Chapter8/共享同一对象的不同成员.h)
add_executable(random_num_generator
        Chapter8/选择合适的引擎生成随机数.cpp
        Chapter8/random_number_generator.h)
target_link_libraries(random_num_generator fmt::fmt)
add_executable(precise_probability
        Chapter8/让STL以指定的分布方式产生随机数.cpp)
