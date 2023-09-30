//
// Created by Momo on 2023/9/20.
//

#include "function_func_wrapper.h"

inline void my_bad() { cout << "what am I doing!\n"; }

inline void you_bad() { cout << "what are you doing!\n"; }

static void demo() {
    // vector.emplace_back()：直接在末尾构造元素，没有拷贝或赋值的开销
    callbacks.emplace_back(::my_bad);
    callbacks.emplace_back(::you_bad);

    // 调用数组里所有的函数
    for (auto && demo: callbacks)
        demo();
}


int main() {
//    cout << add_func(10, 22) << endl;
//    lambda_func();
//    use_other_func(my_bad);
//    use_other_func(you_bad);

    return 0;
}