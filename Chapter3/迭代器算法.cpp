//
// Created by Momo on 2023/9/17.
//

#include "迭代器算法.h"

static void demo() {
    for (const auto &num: fib_range(10))
        cout << num << " ";
    cout << endl;
}

int main() {
    demo();

    return 0;
}