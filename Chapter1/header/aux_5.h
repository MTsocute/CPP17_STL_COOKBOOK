//
// Created by Momo on 2023/9/8.
//

#ifndef STL_AUX_5_H
#define STL_AUX_5_H

#include <iostream>

using namespace std;

template<typename T>
class addable {
    T val;
public:
    explicit addable(T v) : val{v} {}

    // 实现两个不同类型的运算 --> 但是返回值是谁呢
    template<typename U>
    T add(U x) const { return val + x; }
};

template<typename T>
class addable2 {
    T val;
public:
    explicit addable2(T v) : val{v} {}

    // 但是这样子就出了一个问题，要么处理容器，要么处理一个 type
    template<typename U>
    T add(U x) {
        auto copy(val); // Get a copy of the vector member
        for (auto &n: copy)
            n += x;
        return copy;
    }
};

template<typename T>
class addable3 {
    T val;
public:
    explicit addable3(T v) : val{v} {}

    // 但是这样子就出了一个问题，要么处理容器，要么处理一个 type
    template<typename U>
    T add(U x) {
        // constexpr 提前预编译，在执行之前就选择好了
        // is_same_v (a, b) 判断 a, b 是不是同一个类型
        if constexpr (is_same_v<T, std::vector<U>>) {
            auto copy = val;
            for (auto &n: copy) n += x;
            return copy;
        } else return val + x;
    }
};

// 使用 std::enable_if_t() 指定返回类型
/** enable_if_t(expression, type)
    * 如果表达式为 true 返回 type
    * 如果为 false 就不做操作
 * */
void enable_if_t_in_use() {
    // exp == true, then double demo
    std::enable_if_t<is_same_v<int, int>, double> demo;

    if (bool tmp = is_same_v<decltype(demo), double>; tmp)
        cout << "demo is double\n";
    else
        cout << "demo is not a double\n";
}


#endif //STL_AUX_5_H
