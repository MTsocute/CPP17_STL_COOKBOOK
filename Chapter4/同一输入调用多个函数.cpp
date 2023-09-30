//
// Created by Momo on 2023/9/23.
//
#include <iostream>

using namespace std;

int addOne(int x) {
    cout << "I am addOne\n";
    return x + 1;
}

int doubleValue(int x) {
    cout << "I am multiply two\n";
    return x * 2;
}

int subtractThree(int x) {
    cout << "I am sub Three\n";
    return x - 3;
}


/**
 * @brief 实现一个参数同时调用多个 lambda 函数
 * Lambda 表达式的主体实际上是用于调用传递给 multicall 函数的一组函数 functions，并且它不关心这些函数的返回值。
 * Lambda 表达式的返回值是整个初始化列表的结果，但由于我们强制将它转换为 void，所以它的返回值类型是 void。
 * 这就是为什么我们可以说这个 Lambda 表达式只是执行一组函数调用而不返回任何有用的值。
 * */
template<typename ... Ts>
static auto multicall(Ts ...functions) {
    return [=](auto x) {
        // (void) ini_list 声明 我们不需要返回初始化的列表，避免编译器生成警告
        (void) std::initializer_list<int>{
                // TODO:: 实现一个“即用即弃”的函数
                // 这里的 (void) 只是告诉编译器，我们不在乎他返回结果，先进行函数操作
                // 我们要创建一个 ini_list 存储函数调用。我们不关心函数的返回值，只是要用
                // 所以我们使用 “逗号表达式”，最后一个前面都会被使用，但是只有最后一个位置才会赋值
                // 所以，(func, 0) 是用来占据位置的，而不是使用
                ((void) functions(x), 0)...
        };
    };
}

// 实现一个类似于 for_each，所有函数都执行同一个函数的的函数
template<typename F, typename ... Ts>
static auto for_each(F f, Ts ...xs) {
    (void) std::initializer_list<int>{
            ((void) f(xs), 0)...
    };
}

static auto brace_print(char a, char b) {
    return [=](auto x) {
        std::cout << a << x << b << ", ";
    };
}


void demo1() {
    // 定义一些函数
    auto addOneFunc = addOne;
    auto doubleValueFunc = doubleValue;
    auto subtractThreeFunc = subtractThree;

    // 使用 multicall 组合这些函数
    auto combinedFunc = multicall(addOneFunc, doubleValueFunc, subtractThreeFunc);

    // 调用组合的函数
    combinedFunc(5);  // 不会有返回值的，就是单纯的使用
}

int main() {
    auto f(brace_print('(', ')'));
    auto g(brace_print('[', ']'));
    auto h(brace_print('{', '}'));
    auto nl([](auto) { std::cout << '\n'; });

    auto call_fgh(multicall(f, g, h, nl));

    // 多个参数使用 call_fgh，但是 call_fgh 是多个函数的耦合
    // 相当于一次一个参数调用多个函数
    for_each(call_fgh, 1, 2, 3, 4, 5);

    return 0;
}