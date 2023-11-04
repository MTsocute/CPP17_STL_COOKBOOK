//
// Created by Momo on 2023/10/21.
//

#ifndef STL_元组快速构成数据结构_H
#define STL_元组快速构成数据结构_H

#include <range/v3/all.hpp>
#include <fmt/core.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <iomanip>
#include <numeric>
#include <string>
#include <tuple>
#include <list>

//using namespace std;
//namespace rng = ranges;

// Define a tuple
using Foo = std::tuple<int, std::string, float>;


/* 实现一个输出 */
template<typename T, typename ... Ts>
void print_args(std::ostream &os, const T &v, const Ts &...vs) {
    // 这个实现了，不使用递归的情况下，进行额外的操作
    // 相当于并列的进行: cout << ", " << para
    os << v;
    (void) std::initializer_list<int>{
            ((os << ", " << vs), 0)...
    };
}

// 重载，处理空的情况
void print_args(std::ostream &os) {
    // 打印一个空 tuple，不做任何操作
    os << " ";
}

/* 处理 tuple 的输出 */
template<typename ... Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
    os << "(";

    // 相当于传递了 apply 拿到的参数传递给 print_args() 再做处理
    auto print_tuple = [&os](const Ts &... xs) {
        print_args(os, xs...);
    };

    apply(print_tuple, t);

    return os << ")";
}

/* 找到这个范围内的最小值和最大值，还要能对所有值求平均。
 * 并将这 四个值打包入一个元组中 */
template<typename T>
std::tuple<double, double, double, double> sum_min_max_avg(const T &range) {
    auto min_max = std::minmax_element(begin(range), end(range));
    auto sum = std::accumulate(begin(range), end(range), 0.0);

    return {sum, *min_max.first, *min_max.second, sum / range.size()};
}

// 递归函数用于合并多个元组
template <size_t I = 0, typename... Ts> // I 指的是元组中元素的数量
auto zipTuples(const Ts&... tuples) {
    if constexpr (I == 0)   // 当 I 为 0 时，返回一个空元组，递归停止（叶子结点）
        return std::tuple<>();
    else {
        auto previous = zipTuples<I - 1>(tuples...);
        // op(obj)...: 相当于一个个操作
        // 而 tuples...：相当于传参
        return std::tuple_cat(previous,
            std::make_tuple(std::get<I - 1>(tuples)...));
    }
}


#endif //STL_元组快速构成数据结构_H
