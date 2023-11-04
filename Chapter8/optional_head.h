//
// Created by Momo on 2023/10/20.
//

#ifndef STL_OPTIONAL_HEAD_H
#define STL_OPTIONAL_HEAD_H

#include <optional>
#include <fmt/core.h>
#include <iostream>

using namespace std;

using opint = optional<int>;
using opdouble = optional<double>;

// optional: 解决函数返回失败的情况
opdouble get_division(double a, double b) {
    // 返回的不是 a / b 结果，而是一个 optional<double> 对象
    if (b != 0) return a / b;
    // nullopt：表示没有值
    return std::nullopt;
}

void get_ans(const opdouble &d) {
    // optional.has_value()：判断 optional 对象是不是没有值
    if (d.has_value())
        //optional.value()：如果 optional 对象有值，返回对应值
        cout << fmt::format("The Result is: {}\n", d.value());
    else cout << "No value return\n";
}


opdouble operator+(const opdouble & a, const opdouble & b) {
    // 当处于 bool 条件下，我们可以使用 ！optional 对象判断是否有值
    if (!a.has_value() || !b) { return std::nullopt; }
    // 我们可以使用 * optional 对象获取值
    else return a.value() + *b;
}

/* 实现和普通值的 + 运算 */
template<class T>
opdouble operator+(const opdouble & obj, T other) {
    if (!obj) { return nullopt; }
    return *obj + other;
}

/* 实现对于结构体指针访问的需求 */
struct st {
    int a;
    int b;
};
using opstruct = optional<st>;

opstruct getValue(int a, int b) {
    if (a > 0 and b > 0)
        return st {a, b};
    else return std::nullopt;
}

/* 判断结构体是否为空，如果不为空输出其中的值*/
static void judgeAndOutput(const opstruct & s) {
    try {
        cout <<
             fmt::format("a of structure is: {}\n"
                         "b of structure is: {}\n",
                         s.value().a, s.value().b) << endl;
    }
    // bad_optional_access: 没有数据还坚持访问
    catch (std::bad_optional_access &) {
        cout << "Nullopt!\n";
    }
}


#endif //STL_OPTIONAL_HEAD_H
