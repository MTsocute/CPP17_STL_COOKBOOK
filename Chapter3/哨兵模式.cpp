//
// Created by Momo on 2023/9/18.
//

#include "哨兵模式.h"

void demo1() {
    const char *argv = "niamde";

    const char *const param{argv};

    for (char c: cstring_range(param))
        std::cout << c << ' ';
    std::cout << '\n';
}

void demo2() {
    MyNumber num(5);

    // 前置递增
    ++num;
    std::cout << "前置递增后的值: " << num.getValue() << std::endl;

    // 后置递增
    MyNumber num2(10);
    MyNumber result = num2++;
    std::cout << "后置递增后的值: " << num2.getValue() << std::endl;
    std::cout << "后置递增前的值: " << result.getValue() << std::endl;
}

int main() {
    demo2();

    return 0;
}