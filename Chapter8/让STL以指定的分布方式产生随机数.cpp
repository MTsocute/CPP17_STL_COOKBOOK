//
// Created by Momo on 2023/11/4.
//
#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
void print_distro(T distro, size_t samples) {
    default_random_engine e;    // 随机数生成器
    map<int, size_t> m;     // 存储随机数和出现的次数

    // 生成 sample 数量的随机数，存储在字典中
    for (size_t i{0}; i < samples; ++i) {
        // distro 是不同的随机分布，会对生成的随机数进行一个限定，满足一定的概率部分出现
        m[distro(e)] += 1;
    }

    // max_element(): 如果使用 lambda 可以指定比较的方式
    // 比较的是 map，所以我们要自定义比较的是记录出现的次数，即 value
    // 返回的是一个 pair 对的迭代器，所以要用 ->second 获取值
    size_t max_elm(max_element(begin(m), end(m),
                               [](const auto &a, const auto &b) { return a.second < b.second; })->second);

    size_t max_div(max(max_elm / 100, size_t(1)));

    for (const auto [randval, count]: m) {
        // 小于最大长度 1/200 的不输出
        if (count < max_elm / 200) { continue; }

        cout << setw(3) << randval << " : "
             << string(count / max_div, '*') << '\n';
    }
}


static void demo1(const size_t &&samples) {
    cout << "uniform_int_distribution\n";
    // uniform_int_distribution{range}:生成指定范围的随机数，而且数的概率是一样的
    print_distro(uniform_int_distribution<int>{0, 9}, samples);
}

static void demo2(const size_t &sample) {
    // normal_distribution { 均值，标准差 }: 高斯分布
    print_distro(normal_distribution{}, sample);
}


static void demo3(const size_t &samples) {
    cout << "bernoulli_distribution\n";
    // bernoulli_distribution {}:
    print_distro(std::bernoulli_distribution{0.75}, samples);
}

static void demo4(const size_t &samples) {
    cout << "discrete_distribution\n";
    //
    print_distro(discrete_distribution<int>{{1, 2, 4, 8}}, samples);
}

static void demo5(const size_t &samples) {
    initializer_list<int> intervals{0, 5, 10, 30};
    initializer_list<double> weights{0.2, 0.3, 0.5};
    cout << "piecewise_constant_distribution\n";
    // piecewise_constant_distribution {区间，出现的权重}: 控制区间出现的概率
    print_distro(piecewise_constant_distribution<double>{
            begin(intervals), end(intervals),
            begin(weights)}, samples);
}

int main() {
    size_t samples = 1000;
//    demo1(std::move(samples));
//    demo2(samples);
//    demo4(samples);

    demo5(samples);
    return 0;
}