//
// Created by Momo on 2023/9/15.
//

#ifndef STL_逆波兰计算器_H
#define STL_逆波兰计算器_H

#include <iostream>
#include <stack>
#include <iterator>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;
using my_double_func_p = double (*)(double, double);

// 使用函数指针引用 lambda 表达式
map<string, my_double_func_p> ops = {
        {"+", [](double a, double b) { return a + b; }},
        {"-", [](double a, double b) { return a - b; }},
        {"*", [](double a, double b) { return a * b; }},
        {"/", [](double a, double b) { return a / b; }},
        {"^", [](double a, double b) { return pow(a, b); }},
        {"%", [](double a, double b) { return fmod(a, b); }}
};

template<typename IT>
double evaluate_rpn(IT it, IT end) {
    stack<double> val_stack;
    auto pop_stack([&]() {
        auto r(val_stack.top());
        val_stack.pop();
        return r;
    });

    for (; it != end; ++it)     // 遍历外面的字符串
    {
        stringstream ss{*it};   // 相当于一个临时变量
        /* 如果是数字类型的就参与计算 */
        if (double val; ss >> val)  // 相当于实现了类型转变但是是输出流输入到 double 里
            val_stack.push(val);
            /* 如果不是数字类型的就是运算符，开始计算 */
        else {
            assert(val_stack.size() >= 2);  // 至少有两个运算单元才可以运算

            const auto r{pop_stack()};
            const auto l{pop_stack()};

            try {
                // map.at() 安全的访问映射
                val_stack.push(ops.at(*it)(l, r));
            }
            catch (const out_of_range &) {
                throw invalid_argument(*it);
            }
        }
    }
    return val_stack.top();
}

#endif //STL_逆波兰计算器_H
