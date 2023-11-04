//
// Created by Momo on 2023/10/30.
//

#include "random_number_generator.h"

static void demo1() {
    // 创建一个 std::random_device 实例
    std::random_device rd;

    // 使用 random_device 生成随机整数
    size_t random_integer = rd();

    // 使用 random_device 生成随机双精度浮点数
    double random_double = static_cast<double>(rd()) / rd.max();

//    cout << fmt::format("int: {} \ndouble:  {}\n \nunknown: {}", random_integer, random_double);

    cout << fmt::format("Maximum: {}\nNum to divided: {}\n",
                        random_device::max(), ((random_device::max() + 1) / 10));
}

int main(int argc, char **argv) {
//    demo1();

    cout << "\ndefault_random_engine" << '\n';
    size_t partitions = 10;

    size_t samples = 120;

    histogram<default_random_engine>(partitions, samples);

    cout << endl;

    histogram<random_device>(partitions, samples);

    return 0;
}