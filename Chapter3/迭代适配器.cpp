//
// Created by Momo on 2023/9/16.
//

#include <iostream>
#include <iterator>
#include <sstream>
#include <deque>

using namespace std;

void next_in_use() {
    vector<int> v = {10, 20, 30, 40, 80};

    // next(start, offset)：获取从某个位置偏移后该位置的迭代器
    const auto it = next(v.begin(), 3); // --> 40

    cout << "first: " << *it << endl;

    const auto it2 = next(v.begin() + 2, -1);   // --> 20

    cout << "second: " << *it2 << endl;
}

void wrapper() {
    deque<int> v;

    istringstream sstr{"123 456 789"};
    initializer_list<int> il2{-1, -2, -3};

    copy(begin(il2), end(il2), front_inserter(v));

    auto deque_middle = next(begin(v), static_cast<int>(v.size()) / 2);

    copy(istream_iterator<int>{sstr}, {}, inserter(v, deque_middle));

    // 使用 ostream_it 迭代输出内容到屏幕
    copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
    cout << '\n';
}

int main() {
    next_in_use();

    return 0;
}