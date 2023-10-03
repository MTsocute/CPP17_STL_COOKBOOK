//
// Created by Momo on 2023/9/28.
//

#include "容器间的互相拷贝.h"

static void cp_vec_2_map() {
    vector<pair<int, string>> v = {
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
            {5, "five"}
    };

    map<int, string> m;

    // copy_n 使用适配器给不同的类型的容器插入数据
    copy_n(begin(v), 3,
           inserter(m, begin(m)));

    // 创建一个输出用的迭代器
    auto shell_it =
        ostream_iterator<pair<int, string>>{cout, ", "};

    copy(begin(m), end(m), shell_it);
    cout << '\n';
}

int main() {
//    cp_vec_2_map();

    return 0;
}