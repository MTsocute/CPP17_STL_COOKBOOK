//
// Created by Momo on 2023/10/30.
//

#ifndef STL_共享同一对象的不同成员_H
#define STL_共享同一对象的不同成员_H

#include <iostream>
#include <memory>
#include <string>
#include <tuple>

using namespace std;

struct person {
    string name;
    size_t age;

    person(string n, size_t a)
            : name{std::move(n)}, age{a} { cout << "CTOR " << name << '\n'; }

    ~person() { cout << "DTOR " << name << '\n'; }
};

using student_tuple = tuple<size_t, string, double>;

#endif //STL_共享同一对象的不同成员_H
