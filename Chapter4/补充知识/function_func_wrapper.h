//
// Created by Momo on 2023/9/20.
//

#ifndef STL_FUNCTION_FUNC_WRAPPER_H
#define STL_FUNCTION_FUNC_WRAPPER_H

#include <functional>
#include <iostream>

using namespace std;

/* function 包装各类的函数 */

// function 包装 函数
inline int add(int a, int b) { return a + b; }

function<int(int, int)> add_func = add;

// function 包装 lambda 函数
function<void()> lambda_func =
        []() { cout << "Hello Momo!\n"; };

// 使用 function 接受 函数作为参数
void use_other_func(function<void()> && func) {
    cout << "This is Other Func: \n ";
    func();
}

// TODO:: 通用容器创建函数数组
std::vector<function<void()>> callbacks;

#endif //STL_FUNCTION_FUNC_WRAPPER_H
