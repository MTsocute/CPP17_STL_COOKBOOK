//
// Created by Momo on 2023/10/1.
//

#ifndef STL_在有序和无序的VECTOR中查找元素_H
#define STL_在有序和无序的VECTOR中查找元素_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct city {
    string name;
    unsigned population;
};

bool operator==(const city &a, const city &b) {
    return a.name == b.name && a.population == b.population;
}

ostream &operator<<(ostream &os, const city &city) {
    return os << "{" << city.name << ", " << city.population << "}";
}

/**
 * @brief 函数式编程的一个极其重要的思想
 * 分段的处理，有些方法无法在函数里面完成，就丢出去，在外部的时候通过其他方法完成
 * 在接力处理后的对象完成
    * opt_print --> print_city
    * item == data (传递的数据，查找部分我们在外面完成)
 * */
template<typename C>
static auto opt_print(const C &container) {
    // 找对象的过程不再 opt_print 里处理
    return [end_it = container.end()](const auto &item)
    {   // 返回一个函数对象(接受一个迭代器) --> 看找到与否，找打就打印对应的内容
        // 找到的话，使用函数就会输出内容
        if (item != end_it) cout << *item << '\n';
        else cout << "<end>\n";
    };
}

#endif //STL_在有序和无序的VECTOR中查找元素_H
