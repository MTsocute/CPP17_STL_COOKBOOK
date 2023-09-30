//
// Created by Momo on 2023/9/22.
//
#include <iostream>

using namespace std;

// 实现一个嵌套使用多个函数的函数
template<typename T, typename ...Ts>
auto concat(T t, Ts ...ts) {
    // 检测 t 的长度作为多参数模版递归停止的条件
    if constexpr (sizeof...(ts) > 0) {
        // 这里使用 [=] 就是为了让每一层的 lambda 函数传递参数给最后一层的函数使用
        return [=](auto ...parameters) {
            // 第一个() 接受多个参数的 lambda 表达式(ts ...) 接受多个参数
            // 第二个() 是返回的 lambda 表达式接受参数(parameters ...)，再一次返回值给 t
            // 从底层递归函数不断向上返回，t 相当于是上一层的函数
            return t(concat(ts...)(parameters...));
        };
    }
    else {  // 这里已经完成了所有嵌套了，我们只需要返回就能递归到上层，不断返回上层了
        return t;
    }
}

// 简单版本的实现多函数的嵌套
template<typename F, typename G, typename H>
auto concat2(F f, G g, H h) {
    return [=](auto ... params) {
        return f(g(h(params...)));
    };
}

int main() {
    auto twice([](int i) { return i * 2; });
    auto thrice([](int i) { return i * 3; });

    // 实际操作：twice(thrice(plus())) (a, b) 实现 --> twice(thrice(plus(a, b)))
    auto combined(concat(twice, thrice, std::plus<int>{}));

    std::cout << combined(2, 3) << '\n';
}