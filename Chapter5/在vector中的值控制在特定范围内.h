//
// Created by Momo on 2023/10/2.
//

#ifndef STL_在VECTOR中的值控制在特定范围内_H
#define STL_在VECTOR中的值控制在特定范围内_H

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

/**
 * @brief 归一化
 * @brief 这里实现了一个线性的插值映射 val -> [0, new_max]
    * 我们的值都是最大、最小范围之间的，我们最大最小调整为 new_max 和 0
    * 那么对应的 val 就要在这个区间内插值映射
 * */
static auto norm(int min, int max, int new_max) {
    const double diff = max - min;
    return [=](int val) {
        return int((val - min) / diff * new_max);
    };
}

// 外部的函数就是接力传入 max、min 给 clamp()
static auto clampval(int min, int max) {
    return [=](int val) -> int {
        // clamp(): 确保
        // 值不会超出给定的最小值和最大值，如果它超出，修正为最小值或最大值
        return clamp(val, min, max);
    };
}

#endif //STL_在VECTOR中的值控制在特定范围内_H
