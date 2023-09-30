//
// Created by Momo on 2023/9/20.
//

#ifndef STL_使用LAMBDA为FUNCTION添加多态性_H
#define STL_使用LAMBDA为FUNCTION添加多态性_H

#include <functional>
#include <iostream>
#include <deque>
#include <list>

using namespace std;

template<typename C>
static auto consumer(C &container) {
    // 这个 & 是为了可以真正的改变到 container
    // 返回一个可以修改 container 的函数
    return [&](auto value) { container.emplace_back(value); };
}

template<typename C>
static auto consumer(C &&container) {
    return [&](auto value) { container.emplace_back(value); };
}

// 输出函数里面的所有内容
template<typename C>
static void print(const C &c) {
    for (auto i: c)
        std::cout << i << ", ";
    std::cout << '\n';
}

#endif //STL_使用LAMBDA为FUNCTION添加多态性_H
