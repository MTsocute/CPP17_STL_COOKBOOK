//
// Created by Momo on 2023/10/29.
//

#ifndef STL_智能指针简化处理遗留API问题_H
#define STL_智能指针简化处理遗留API问题_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;


class Foo {
private:
    string name;

    /* 构造函数和析构函数存储到 private 模拟无法直接创造和销毁对象实例的情况 */
    explicit Foo(string n)
            : name{std::move(n)} { cout << "CTOR " << name << '\n'; }

    ~Foo() { cout << "DTOR " << name << '\n'; }

public:
    // 使用裸指针操作，模拟 C 风格的 API 处理
    static Foo *create_foo(string s) { return new Foo{std::move(s)}; }

    static void destroy_foo(Foo *p) { delete p; }
};

static shared_ptr<Foo> make_shared_foo(string s) {
    // 构建自定义删除器
    return {Foo::create_foo(std::move(s)), Foo::destroy_foo};
}

static unique_ptr<Foo, void (*)(Foo *)> make_unique_foo(string s) {
    return {Foo::create_foo(std::move(s)), Foo::destroy_foo};
}

#endif //STL_智能指针简化处理遗留API问题_H
