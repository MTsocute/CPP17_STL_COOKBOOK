//
// Created by Momo on 2023/10/3.
//
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <map>
#include <iomanip>

using namespace std;

// 直方图的形式输出采样的数据
static void better_view(const vector<int> &sample) {
    map<int, size_t> hist;
    for (auto i: sample) {
        auto [k_v, success] = hist.try_emplace(i, 0);
        if (!success) k_v->second += 1;
    }

    for (const auto &[value, count]: hist) {
        cout << setw(2) << value << " "
             // string(number, obj)：相当于 print("*" * number)
             << string(count, '*') << '\n';
    }
}

int main() {
    const size_t data_points = 100000;   // vector 的长度
    const size_t sample_points = 100;    // 采样的步长

    /* 使用正态分布随机生成器填充 vector */
    const int mean = 10;    // 平均值
    const size_t dev = 3;   // 标准值

    // 随机数的创建
    random_device rd;
    mt19937 gen{rd()};
    normal_distribution<> d{mean, dev};    // 正态分布随机数生成器

    vector<int> v;  // 存随机数据用的 vector
    v.reserve(data_points);

    /* 填充随机数到容器当中 */
    // generate_n(): 使用自定义的函数生成指定数量的函数到容器中去
    generate_n(back_inserter(v), data_points,
               [&] { return d(gen); });

    vector<int> samples;
    v.reserve(sample_points);

    // sample(): 随机的采样数据放到容器中去
    std::sample(v.begin(), v.end(), back_inserter(samples),
                // 这里新的一个随机数生成器是为了保证和上面那个不同，确保随机性
                sample_points, mt19937 { random_device{} ()});

    better_view(samples);

    return 0;
}