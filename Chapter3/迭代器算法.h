//
// Created by Momo on 2023/9/17.
//

#ifndef STL_迭代器算法_H
#define STL_迭代器算法_H

#include <iostream>

using namespace std;

class fibit {
private:
    size_t i{0};    // i 斐波那契数列需要迭代的次数
    size_t a{0};    // 保存为斐波那契数列的前两项的第一个
    size_t b{1};    // 保存为斐波那契数列的前两项的第二个

public:
    fibit() = default;

    explicit fibit(size_t i_) : i{i_} {}

    size_t operator*() const { return b; }

    // 当移动迭代器 ++ 时，其会移动到下一个斐波那契数上
    constexpr fibit &operator++() {
        const size_t old_b{b};
        b += a;
        a = old_b;
        ++i;
        return *this;
    }

    bool operator!=(const fibit &o) const { return i != o.i; }

    bool operator==(const fibit &o) const { return !((*this).i != o.i); }
};

class fib_range {
    size_t end_n;

public:
    fib_range(size_t end_n_) : end_n{end_n_} {}

    fibit begin() const { return fibit{}; }

    fibit end() const { return fibit{end_n}; }
};


#endif //STL_迭代器算法_H
