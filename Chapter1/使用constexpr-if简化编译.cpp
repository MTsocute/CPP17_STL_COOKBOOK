//
// Created by Momo on 2023/9/8.
//
#include "header/aux_5.h"

void demo1() {
    addable<int> a(10);
    // 虽然不确定返回值是啥但是至少可以返回
    cout << a.add(14.51) << endl;

    cout << addable<int>{12}.add(13) << endl;

    addable<string> b("momo");
    cout << b.add(" love animation!\n");
}

void demo2() {
    vector<int> v = {1, 2, 3};

    addable<vector<int>> demo(vector<int> v); // --> T = vector<int>
    // 错误操作
//    addable<vector<int>> {v}.add(10);   // --> U = int

    addable2<vector<int>>{v}.add(20);

    // 无法处理 type
//    cout << addable2<int> {20}.add(30) << endl;

    cout << addable3<int> {20}.add(30.213) << endl;

    auto && tmp = addable3<vector<int>> {v}.add(30);

    for (const auto & num : tmp)
        cout << num << " ";
    cout << endl;
}

int main() {

    return 0;
}