//
// Created by Momo on 2023/9/8.
//
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;

    // 结构体构造函数
    Point(int initialX, int initialY) {
        x = initialX;
        y = initialY;
    }
};


struct demo2 {
    int x, y;

    // 结构体列表成员初始化
    demo2(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

// 结构体也可以是模版类型的
template<class T>
struct demo_template {
    T data;

    explicit demo_template(T data_) : data(data_) {
        std::cout << "Generic Constructor" << std::endl;
    }
};

// Specialization for int
template <>
struct demo_template<int> {
    int data;

    explicit demo_template(int data_) : data(data_) {
        std::cout << "Constructor for int" << std::endl;
    }
};


int main() {
//    demo2 d(10);
//    cout << d.x << " " << d.y << endl;

    demo_template<int> d1(123);



    return 0;
}
