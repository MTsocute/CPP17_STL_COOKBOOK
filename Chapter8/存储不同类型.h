//
// Created by Momo on 2023/10/24.
//

#ifndef STL_存储不同类型_H
#define STL_存储不同类型_H

#include <iostream>
#include <fmt/core.h>
#include <utility>
#include <variant>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class cat {
    string name;
public:
    explicit cat(string n) : name{std::move(n)} {}

    void meow() const {
        cout << name << " says Meow!\n";
    }
};

class dog {
    string name;
public:
    explicit dog(string n) : name{std::move(n)} {}

    void woof() const {
        cout << name << " says Woof!\n";
    }
};

// variant 存储多个类型
using animal = variant<dog, cat>;

template<class T>
bool is_type(const animal &a) {
    // hold_alternative: 判断接受参数 variant 是否是指定的类型：看 demo1()｜demo4()
    return holds_alternative<T>(a);
}

// 双重函数对象
struct animal_voice {
    void operator()(const dog &d) const {
        d.woof();
    }

    void operator()(const cat &c) const {
        c.meow();
    }
};


#endif //STL_存储不同类型_H
