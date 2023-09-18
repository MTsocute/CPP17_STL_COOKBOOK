//
// Created by Momo on 2023/9/18.
//

#ifndef STL_反向迭代器_H
#define STL_反向迭代器_H

#include <list>
#include <iostream>
#include <iterator>

using namespace std;


void demo1() {
    list<int> l = {10, 20, 30, 14, 19};
    // 一般情况下的反向迭代
    for (auto s = l.rbegin(); s != l.rend(); s++)
        cout << *s << " ";
    cout << endl;
}

void demo2() {
    vector<int> v = {1,2,3,4,5};

    // make_reverse_iterator() 创建反向迭代器

    auto s = make_reverse_iterator(v.end());
    auto e = make_reverse_iterator(v.begin());

    for (; s != e; s++)
        cout << *s << " ";
    cout << endl;
}


#endif //STL_反向迭代器_H
