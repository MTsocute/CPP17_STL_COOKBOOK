//
// Created by Momo on 2023/10/28.
//

#ifndef STL_对共享对象使用弱指针_H
#define STL_对共享对象使用弱指针_H

#include <iostream>
#include <memory>
#include <fmt/core.h>

using namespace std;

struct Foo {
    int value;

    explicit Foo(int i) : value{i} {}

    ~Foo() { cout << "DTOR Foo " << value << '\n'; }
};

// 指向共享对象，但是不会持有控制权
void weak_ptr_info(const weak_ptr<Foo> &p) {
    cout << "---------" << boolalpha
         // weak_pointer.expired(): 告诉我们弱指针指向的共享概念股对象是否还存在
         << "\nexpired:   " << p.expired()
         // weak_pointer.use_count(): share 示例对象被引用的次数
         << "\nuse_count: " << p.use_count()
         << "\ncontent:   ";

    if (const auto sp = p.lock(); sp)
        cout << sp->value << '\n';
    else cout << "<null>\n";
}

#endif //STL_对共享对象使用弱指针_H
