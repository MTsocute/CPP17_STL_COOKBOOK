//
// Created by Momo on 2023/10/27.
//

#ifndef STL_自动化规划资源管理_H
#define STL_自动化规划资源管理_H

#include <iostream>
#include <memory>

using namespace std;

class Foo {
public:
    string name;
    explicit Foo(string n) : name(std::move(n)) {};
    ~Foo() { cout << "DTOR " << name << '\n'; }
};

void process_item(unique_ptr<Foo> p) {
    if (!p) return;
    cout << "Processing" << p->name << endl;
}

static void demo1() {
    // unique指针的创建
    unique_ptr<Foo> p1 {new Foo{"demo"}};   // 显式
    auto p2 (make_unique<Foo>("Beelfoo"));  // 隐式

    if (!p2) return;
    cout << p2->name << endl;
}

static void demo2() {
    // 创建一个std::unique_ptr，指向int类型的动态分配对象
    std::unique_ptr<int> uniqueIntPtr(new int(42));

    // get()函数获得托管对象的指针，然后解引用
    int* rawPtr = uniqueIntPtr.get();

    // 现在可以使用rawPtr来访问对象
    if (rawPtr)
        std::cout << "Dereferenced value: " << *rawPtr << std::endl;
    else std::cout << "uniqueIntPtr is empty." << std::endl;
}

static void demo3() {
    // unique 指针的独占动态对象，动态对象的所有权只能靠 move() 转移

    // std::unique_ptr的所有权独占，以下操作是不允许的
    auto demo  = make_unique<Foo>(Foo{"animal"});
    // process_item(demo);  // 错误

    process_item(std::move(demo));
}

#endif //STL_自动化规划资源管理_H
