//
// Created by Momo on 2023/9/22.
//

#ifndef STL_通过逻辑连接创建复杂谓词_H
#define STL_通过逻辑连接创建复杂谓词_H

#include <iostream>
#include <string>

using namespace std;

// 第一个谓词会告诉我们字符 串的首字母是否是 a
static bool begins_with_a(const std::string &s) {
    return s.find('a') == 0;
}

// 第二个谓词则会告诉我们字符串的结尾字母是否为 b
static bool ends_with_b(const std::string &s) {
    return s.rfind('b') == s.length() - 1;
}

template<typename A, typename B, typename F>
auto combine(F binary_func, A a, B b) {
    return [=](auto param) {
        return binary_func(a(param), b(param));
    };
}

#endif //STL_通过逻辑连接创建复杂谓词_H
