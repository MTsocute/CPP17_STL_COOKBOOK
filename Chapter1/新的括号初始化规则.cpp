//
// Created by Momo on 2023/9/8.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // auto 可以有 = 的 多元素 {} 为 initializer_list<> 类型
    auto ini_list = {1,2,3};

    // 不可以省略 = ，会报错
//    auto ini_list2 {1,2,3};

    // {} 只有一个元素，就是该元素类型，不会是一个 ini_list

    vector<int> v;

    for (const auto & it : ini_list)
        v.push_back(it);

    for (const auto & data: v)
        cout << data << endl;

    return 0;
}