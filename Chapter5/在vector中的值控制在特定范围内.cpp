//
// Created by Momo on 2023/10/2.
//

#include "在vector中的值控制在特定范围内.h"


int main() {
    vector<int> v{0, 1000, 5, 250, 300, 800, 900, 321};

    // 输出数组中的元素
    copy(begin(v), end(v),
         ostream_iterator<int>{cout, ", "});
    cout << '\n';

    // 找到容器中的最大和最小的元素
    const auto [min_it, max_it] =
            minmax_element(begin(v), end(v));

    vector<int> v_norm;
    // vector.reserve(): 预留一定量的内存大小，避免动态分配的开销
    v_norm.reserve(v.size());

    transform(begin(v), end(v), back_inserter(v_norm),
              norm(*min_it, *max_it, 255));

    // 输出 norm() 归一化后的数组内容
    copy(begin(v_norm), end(v_norm),
         ostream_iterator<int>{cout, ", "});
    cout << '\n';

    transform(begin(v), end(v),
              begin(v_norm), clampval(0, 255));

    // 输出 clampval() 归一化之后的结果
    copy(begin(v_norm), end(v_norm),
         ostream_iterator<int>{cout, ", "});
    cout << '\n';

    return 0;
}