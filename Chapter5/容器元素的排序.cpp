//
// Created by Momo on 2023/9/28.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>
#include <iomanip>

using namespace std;

// 自定义的输出方法
static void print(const vector<int> &v) {
    copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
    cout << '\n';
}

void demo1() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 创建随机数的方法
    random_device rd;   // 生成随机种子
    mt19937 g{rd()};    // 生成随机数

    // is_sorted() 判断是否排序好
    std::cout << (is_sorted(begin(v), end(v)) ? "true" : "false") << '\n';

    // shuffle() 打乱排序的顺序
    shuffle(begin(v), end(v), g);

    std::cout << (is_sorted(begin(v), end(v)) ? "true" : "false") << '\n';
    print(v);

    sort(begin(v), end(v));

    std::cout << (is_sorted(begin(v), end(v)) ? "true" : "false") << '\n';
    print(v);

    shuffle(begin(v), end(v), g);

    // partition(): 把容器分割两部分，符合条件到前面，不符合到后面
    auto partitionPoint =   // 返回值就是分段点的位置
            partition(begin(v), end(v), [](int i) { return i < 5; });

    print(v);

    shuffle(begin(v), end(v), g);

    auto middle(next(begin(v), int(v.size()) / 2));

    // parital_sort(): 不完全的排序，最小的几个放前面，最大的放后面
    partial_sort(begin(v), middle, end(v));

    print(v);
}


void demo2() {
    struct mystruct {
        int a;
        int b;
    };

    vector<mystruct> mv = {
            {5,    100},
            {1,    50},
            {-123, 1000},
            {3,    70},
            {-10,  20}
    };

    sort(begin(mv), end(mv),
          // 实现 mystruct 类型的排序: 从小到大
         [](const mystruct &lhs, const mystruct &rhs) { return lhs.b < rhs.b; }
    );

    for (const auto &[a, b]: mv)
        cout << "{" << a << ", " << b << "} ";
    cout << '\n';
}


int main() {
    demo1();
//    demo2();

    return 0;
}