//
// Created by Momo on 2023/10/21.
//

#include "对元组使用函数.h"


student momo = {10086, "momo", 114.514};

auto arguments_for_later = {
        make_tuple(234, "John Doe"s, 3.7),
        make_tuple(345, "Billy Foo"s, 4.0),
        make_tuple(456, "Cathy Bar"s, 3.5),
};


static void demo1() {
    // 比较不方便的元组解包调用
    print_student(get<0>(momo), get<1>(momo), get<2>(momo));
    // 看起来还是有点麻烦，我们看例 2
    const auto &[id, name, gpa] = momo;
    print_student(id, name, gpa);
}

static void demo2() {
    void (*funcP)(size_t, const string &, double) = print_student;


    /** std:apply()：
     * 接受两个参数： 一个函数指针或者函数对象，和一个元组
     * 自动的把元组中的变量，传递给对应的函数参数
     * */
    std::apply(print_student, momo);
    std::apply(funcP, momo);
}

static void demo3() {
    for (const auto &args: arguments_for_later)
        apply(print_student, args);
    cout << "-----\n";
}

int main() {
//    demo1();
//    demo2();
//    demo3();
    return 0;
}