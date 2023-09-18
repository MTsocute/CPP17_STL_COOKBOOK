//
// Created by Momo on 2023/9/18.
//

#ifndef STL_哨兵模式_H
#define STL_哨兵模式_H

#include <iostream>

class cstring_iterator_sentinel {
};

class cstring_iterator {
    const char *s{nullptr};

public:
    explicit cstring_iterator(const char *str) : s{str} {}

    char operator*() const { return *s; }

    cstring_iterator &operator++() {
        ++s;
        return *this;
    }

    // 迭代器同哨兵进行比较
    bool operator!=(const cstring_iterator_sentinel) const {
        return s != nullptr && *s != '\0';
    }
};

class cstring_range {
    const char *s{nullptr};

public:
    cstring_range(const char *str) : s{str} {}

    cstring_iterator begin() const { return cstring_iterator{s}; }

    cstring_iterator_sentinel end() const { return {}; }
};

// 类中 前后 ++ 运算的实现
class MyNumber {
private:
    int value;

public:
    explicit MyNumber(int val) : value(val) {}

    // 前置递增操作符 (++myNumber)
    MyNumber &operator++() {
        value++;
        return *this;
    }

    // 后置递增操作符 (myNumber++)
    MyNumber operator++(int) {
        MyNumber temp(*this); // 创建一个临时副本
        value++;
        return temp; // 返回之前的值
    }

    int getValue() const {
        return value;
    }
};

#endif //STL_哨兵模式_H
