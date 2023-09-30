//
// Created by Momo on 2023/9/19.
//
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

// 使用结构体创建一个 lambda 的效果
struct name_greeter {
    std::string name;

    void operator()() const {
        std::cout << "Hello, " << name << '\n';
    }
};

void demo1() {
    name_greeter demo1{"momo"};
    demo1();

    // lambda 实现同样效果
    // 不需要传入参数的 lambda 函数甚至可以不要 ()
    auto greet_john_doe = [] {
        std::cout << "Hello, John Doe\n";
    };

    greet_john_doe();
}

void demo2() {
    int count = 0;
    // mutable 允许 lambda 修改外部引入内部的变量，但不会真的改变外部
    auto add2 = [count]() mutable { return ++count; };

    // 使用 [] 创建变量，虽然不在函数内部，但是只有内部可以访问到
    auto add = [count2 = 0]() mutable { return ++count2; };

    for (int i = 0; i < 10; ++i)
        cout << add() << " ";
    cout << endl;
}

void demo3() {
    int outside_i = 10;
    // [=] 捕获所有的外部变量到 lambda 内部
    auto demo1 = [=] { return outside_i * 10; };

    auto demo2 = [=]() mutable {
        for (int i = 0; i < 10; ++i)
            outside_i += 20;
        return outside_i;
    };

    // :: 调用全局函数，没有就是局部优先
//    cout << demo1() << endl;    // 所以这里的事 demo3 内部的 demo1()

    cout << demo2() << endl;
}

void demo4() {
    // constexpr 在编译前运算，提供会报错
    auto l1 = []()constexpr {
        return max(10, 30);
    };

    cout << "Data = " << l1() << endl;
}

int main() {
//    demo2();
//    demo3();
    demo4();

    return 0;
}