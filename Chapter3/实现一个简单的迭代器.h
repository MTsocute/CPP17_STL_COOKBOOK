//
// Created by Momo on 2023/9/16.
//

#ifndef STL_实现一个简单的迭代器_H
#define STL_实现一个简单的迭代器_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class num_iterator;


/**
 * @brief 兼容自定义迭代器和STL算法
 * 这个特化就 是告诉STL我们的
    * num_iterator 是一种前向迭代器，
    * 并且指向的对象是 int 类 型的值
 * */
namespace std {
    template<>
    struct iterator_traits<num_iterator> {
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
    };
}

// 迭代器类
class num_iterator {
    int i;
public:
    // 类列表初始化，但是使用 { }
    explicit num_iterator(int position = 0) : i{position} {}

    int operator*() const { return i; }

    num_iterator &operator++() {
        ++i;
        return *this;   // != 比较的是 迭代器类对象，所以返回值是自身
    }

    bool operator!=(const num_iterator &other) const {
        return i != other.i;
    }

    // 利用之前实现过的函数，实现新的关系
    bool operator==(const num_iterator &other) const {
        return !(*this != other);   // 偷懒一下，直接用上面实现的取反
    }
};

class num_range {
    int a;
    int b;

public:
    num_range(int from, int to) : a{from}, b{to} {}

    num_iterator begin() const { return num_iterator{a}; }

    num_iterator end() const { return num_iterator{b}; }
};


#endif //STL_实现一个简单的迭代器_H
