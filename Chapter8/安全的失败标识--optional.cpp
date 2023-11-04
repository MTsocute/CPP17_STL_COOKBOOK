//
// Created by Momo on 2023/10/20.
//
#include "optional_head.h"


static void demo1() {
    auto d1 = get_division(13.2, 2.0);
    auto d2 = get_division(3.2, 0);

    get_ans(d1);
    get_ans(d2);
}

static void demo2() {
    auto d1 = get_division(10.2, 4);
    auto d2 = get_division(4.8, 1.2);

    cout << *(d1 + d2 + 20) << endl;
}

static void demo3() {
    opstruct s = st{20, 30};

    auto s1 = getValue(40, 80);
    auto s2 = getValue(10, -30);

    judgeAndOutput(s1);
    judgeAndOutput(s2);
}

static void demo4() {
    opint optValue; // 一个可选的整数

    // value_or(): 如果optValue为空，返回默认值
    int result = optValue.value_or(42);

    std::cout << "Result: " << result << std::endl;

    // 现在给optValue赋一个值
    optValue = 100;

    // 再次使用value_or，此时optValue包含值
    result = optValue.value_or(42);

    std::cout << "Result: " << result << std::endl;
}

int main() {
//    demo1();
//    demo2();
    demo3();
//    demo4();

    return 0;
}
