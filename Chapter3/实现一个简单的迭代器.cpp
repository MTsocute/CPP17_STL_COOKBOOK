//
// Created by Momo on 2023/9/16.
//

#include "实现一个简单的迭代器.h"

std::vector<int> createVector() {
    std::vector<int> temp;
    // 填充 temp
    return temp;  // 使用移动语义返回 temp
}

// 移动语义避免拷贝
static void guess1() {
    // 两个都是对的，但是值得注意的是，第二个表达式意思更加清晰明了
    std::vector<int> &&vec = createVector();
    vector<int> vec2 = std::move(createVector());
}

void demo1() {
    num_range r{100, 110};

    // for : 会调用 r 的 begin() 和 end() 函数
    // 然后不断的迭代 ++ begin，直到 end() 函数
    for (int i: r)
        std::cout << i << ", ";
    std::cout << '\n';
}

//void demo2() {
//    num_range r{100, 110};
//
//    auto [min_it, max_it] =
//            // minmax_element(): 找到容器范围内，最大和最小值的的迭代器，作为 pair 返回
//            std::minmax_element(std::begin(r), std::end(r));
//    std::cout << *min_it << " - " << *max_it << '\n';
//}
//
//void demo3() {
//    for (int i = 0; i <= 10; ++i)
//        cout << i << " ";
//    cout << endl;
//
//    for (int i = 0; i <= 10; i++)
//        cout << i << " ";
//    cout << endl;
//}


int main() {
//    demo1();
//    demo2();
//    demo3();

    int i = 0;
    for (; i <= 10; ++i)
        cout << i << " ";
    cout << i << endl;
    return 0;
}

