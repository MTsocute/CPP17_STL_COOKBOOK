//
// Created by Momo on 2023/10/30.
//

#ifndef STL_RANDOM_NUMBER_GENERATOR_H
#define STL_RANDOM_NUMBER_GENERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <fmt/core.h>

using namespace std;

static void printChart(const vector<size_t> &v, int partitions, int max_div) {
    for (size_t i{0}; i < partitions; ++i)
        cout << setw(2) << i << ": "
             << string(v[i] / max_div, '*') << '\n';
}

/**
 * @brief 使用随机生成器画直方图
 * @param partitions 分成多少个组
 * @param samples 使用迭代器生成随机数的个数
 * */
template<typename RD>
void histogram(size_t partitions, size_t samples) {
    // typename 模版::result_type 成员变量获取模版的推导结果的类型
    using rand_t = typename RD::result_type;    // 获取迭代器数据的类型

    // 确保 partitions ≥ 10
    partitions = max<size_t>(partitions, 10);

    RD rd;  // 实例一个迭代器对象

    /** div 划分值的区间个数为 partitions \n
     * 譬如我们最大值 20，我们划分 4 个区间就是
     * [0, 5] - [6, 10], ... 这样子
     * */
    // 迭代器::max()：获取迭代器最大值
    rand_t div = (double(RD::max()) + 1) /
                 static_cast<double_t>(partitions);

    vector<size_t> v(partitions);   // 存储不同区间的值

    // 迭代器对象 rd()：生成一个随机数
    for (size_t i{0}; i < samples; ++i)
        ++v[rd() / div];    // 记录不同区间值出现的次数

    // 记录出现频率最高的区间
    rand_t max_elm = *max_element(begin(v), end(v));

    // 控制直方图的最高高度别太长，如果很短的话，就用 1，1 做除法就是原数据高度
    rand_t max_div = max(max_elm / 100, rand_t(1));

    printChart(v, partitions, max_div);
}

#endif //STL_RANDOM_NUMBER_GENERATOR_H
