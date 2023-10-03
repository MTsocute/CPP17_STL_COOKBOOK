//
// Created by Momo on 2023/9/28.
//

#ifndef STL_容器间的互相拷贝_H
#define STL_容器间的互相拷贝_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <iterator>
#include <algorithm>

using namespace std;


// 更好的输出打印
namespace std {
    // cout << 如果跟的是一个 pair<int, string> 对象，就会使用下面的格式输出
    ostream &operator<<(ostream &os, const pair<int, string> &p) {
        return os << "(" << p.first << ", " << p.second << ")";
    }
}
#endif //STL_容器间的互相拷贝_H
