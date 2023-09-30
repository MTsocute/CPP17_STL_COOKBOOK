//
// Created by Momo on 2023/9/20.
//

#include "使用lambda为function添加多态性.h"

void demo1() {
    std::deque<int> d;
    std::list<int> l;
    std::vector<int> v;

    // 使用 function<type> 包装"lambda"为数组
    const std::vector<std::function<void(int)> > consumers{
            // 使用了 consumer(container) 返回了 lambda 函数包装起来
            consumer(d),
            consumer(l),
            consumer(v)
    };

    for (size_t i{0}; i < 10; ++i)
        // 获取的是 consumer(container) 返回的临时变量，所以我们要用 &&
        for (auto &&consume: consumers)
            // 虽然我们的 lambda 函数是接受 auto 的参数的，但是我们要保持和模板类型一致
            consume(static_cast<int>(i));

    print(d);
    print(l);
    print(v);
}

void demo2() {
    vector<int> v = {10};
    auto mine = consumer(v);

    mine(30);
    mine(50);

    print(v);
}

int main() {
//    demo2();

    return 0;
}