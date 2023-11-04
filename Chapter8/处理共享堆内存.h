//
// Created by Momo on 2023/10/27.
//

#ifndef STL_处理共享堆内存_H
#define STL_处理共享堆内存_H

#include <iostream>
#include <memory>

using namespace std;

class Foo {
public:
    string name;

    Foo(string n)
            : name{move(n)} { cout << "CTOR " << name << '\n'; }

    ~Foo() { cout << "DTOR " << name << '\n'; }
};

void f(shared_ptr<Foo> sp) {
    // shared_pointer.count()：显示共享对象的数量
    cout << "f: use counter at " << sp.use_count() << '\n';
}

#endif //STL_处理共享堆内存_H
