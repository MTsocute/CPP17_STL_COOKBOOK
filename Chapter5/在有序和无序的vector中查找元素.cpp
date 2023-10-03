//
// Created by Momo on 2023/10/1.
//
#include "在有序和无序的vector中查找元素.h"

const vector<city> c{
        {"Aachen",       246000},
        {"Berlin",       3502000},
        {"Braunschweig", 251000},
        {"Cologne",      1060000}
};
auto print_city = opt_print(c);

void demo1() {
    // 返回的是 Cologne 在 c 中的位置的迭代器
    auto colo_pos =
            // find()：返回容器中指定内容的元素位置的迭代器
            find(c.begin(), c.end(), city{"Cologne", 1060000});

    print_city(colo_pos);
}

void demo2() {
    // find_if()：返回第一个满足条件元素的迭代器
    auto colo_pos =
            find_if(c.begin(), c.end(),
                    [](const auto &item) { return item.name == "Cologne"; });

    print_city(colo_pos);
}

void demo3() {
    // 使用 lambda 更好的创建谓词
    auto population_more_than([](unsigned i) {
        return [=](const city &item) { return item.population > i; };
    });

    auto found_large =
            find_if(begin(c), end(c), population_more_than(2000000));
    print_city(found_large);
}

// next_permutation(): 改变当前元素排序的顺序
void demo4() {
    std::vector<int> v = {1, 2, 3};
    do {
        // 输出当前排列
        for (int num: v) std::cout << num << ' ';
        std::cout << '\n';
    } while (std::next_permutation(v.begin(), v.end()));
}

int main() {
//    demo2();

    vector<int> tmp = {10, 20, 88, 992, 132, 8888, 25040};

    /**
     * equal_range(): 返回一个范围的迭代器
     * 会返回一组 迭代器。第一个迭代器是指向第一个不小于给定值的元素
     * 第二个迭代器指向 第一个大于给定值的元素
     * */
    auto [lower_it, upper_it](
            equal_range(begin(tmp), end(tmp), 992));

    auto print_range = opt_print(tmp);

    print_range(lower_it);
    print_range(upper_it);

    return 0;
}
