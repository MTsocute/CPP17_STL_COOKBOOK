//
// Created by Momo on 2023/10/21.
//

#ifndef STL_对元组使用函数_H
#define STL_对元组使用函数_H

#include <fmt/core.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <string>
#include <tuple>
#include <list>

using namespace std;
using student = tuple<size_t, string, double>;  // 注意这个是元组类型

// 输出学生基本信息
static void print_student(size_t id, const string &name, double gpa) {
    cout << "Student " << quoted(name)
         << ", ID: " << id
         << ", GPA: " << gpa << '\n';
}
#endif //STL_对元组使用函数_H
