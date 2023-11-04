//
// Created by Momo on 2023/10/21.
//

#include "元组快速构成数据结构.h"

using std::cout;
using std::endl;


inline static void demo1() {
    print_args(std::cout, "fuck", "you", "asshole");
}

static void demo2() {
    auto t = std::make_tuple("UpDown", "Funk", 123);
    auto t2 = Foo{10086, "momo", 789.123};
    std::tuple<> t3{};

    cout << t2 << endl;
    cout << t3 << endl;
}

static void demo3() {
    auto numbers = {0.0, 1.0, 2.0, 3.0, 4.0};
    auto t = sum_min_max_avg(numbers);

    cout << t << endl;
}

static void demo4() {
    auto student_desc(std::make_tuple("ID", "Name", "GPA"));
    auto student(std::make_tuple(123456, "John Doe", 3.7));;

    // tuple_cat() 合并两个元组
    cout << tuple_cat(student_desc, student) << '\n';
}

// 尝试使用 zip 合并元组
static void demo5() {
    auto student_desc(std::make_tuple("ID", "Name", "GPA"));
    auto student(std::make_tuple(123456, "John Doe", 3.7));

    auto demo = zipTuples<0>(student_desc, student);

    cout << demo << endl;
}

int main() {
//    demo1();
    demo2();
//    demo3();
//    demo4();
    demo5();

    return 0;
}
