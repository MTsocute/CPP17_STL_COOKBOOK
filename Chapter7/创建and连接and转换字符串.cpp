//
// Created by Momo on 2023/10/6.
//
#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <algorithm>

using namespace std;
using namespace std::literals;

static void demo1() {
    string a {"a"};
    auto b{"b"s};   // 字符串后面 s 编译器会自动推断其为 string 类型

    string_view c {"c"};    // string_view 对象的创建

    auto d {"d"sv}; // 字符串后面跟 sv 快速创建 string_view 对象12

    cout << a << ", " << b << '\n';
    cout << c << ", " << d << '\n';
}

static void demo2() {
    ostringstream o;

    o << "a" << " " << "b" << " " << "c" << " " << "d";

    // 转变 ostreamstring 为 string
    auto concatenated {o.str()};

    cout << concatenated << endl;

    std::transform(concatenated.begin(), concatenated.end(),
              concatenated.begin(), ::toupper);
    cout << concatenated << endl;
}

int main() {
//    demo1();
    demo2();
    return 0;
}