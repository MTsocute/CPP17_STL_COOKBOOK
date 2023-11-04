//
// Created by Momo on 2023/10/28.
//

#include "对共享对象使用弱指针.h"

// 弱指针一般使用
static void demo1() {
    auto shared = make_shared<int>(42);
    weak_ptr<int> weak = shared;    // 使用弱指针指向 共享指针

    // 获取共享指针
    if (auto sharedCopy = weak.lock())
        std::cout << "Shared pointer value: " << *sharedCopy << std::endl;
    else std::cout << "Shared pointer is no longer valid.\n";

    // 释放共享指针
    shared.reset();

    if (auto sharedCopy = weak.lock()) {
        std::cout << "Shared pointer value: " << *sharedCopy << std::endl;
    } else std::cout << "Shared pointer is no longer valid.\n";
}

// 弱指针的 use_count()
static void demo2() {
    std::shared_ptr<int> shared1 = std::make_shared<int>(42);
    auto shared2 = shared1;
    std::weak_ptr<int> weak = shared1;

    // 输出 2，因为有两个共享指针引用了对象
    std::cout << "use_count for weak: " << weak.use_count() << std::endl;

    shared1.reset(); // 释放 shared1，但 shared2 仍然有效
    // 输出 1，因为只有 shared2 仍然引用了对象
    std::cout << "use_count for weak: " << weak.use_count() << std::endl;

    shared2.reset(); // 释放 shared2，没有共享指针引用对象
    // 输出 0，因为没有共享指针引用了对象
    std::cout << "use_count for weak: " << weak.use_count() << std::endl;
}

static void demo3() {
    weak_ptr<Foo> weak_foo;
    weak_ptr_info(weak_foo);    // 打印空的弱指针

    {   // 指向一个 share 指针，share 存在, .use_count()就是 1 了
        auto shared_foo = make_shared<Foo>(1337);
        weak_foo = shared_foo;
        weak_ptr_info(weak_foo);
    }

    weak_ptr_info(weak_foo);
}

int main() {
//    demo1();
    demo2();

    return 0;
}