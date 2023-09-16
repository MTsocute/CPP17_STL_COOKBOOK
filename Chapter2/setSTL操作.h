//
// Created by Momo on 2023/9/14.
//

#ifndef STL_SETSTL操作_H
#define STL_SETSTL操作_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>

using namespace std;

void demo1();

void inserter_in_use();

void copy_in_use();

template<class T>
static void show_data(const vector<T> &v) {
    for (const auto &data: v)
        cout << data << " ";
    cout << endl;
}

#endif //STL_SETSTL操作_H
