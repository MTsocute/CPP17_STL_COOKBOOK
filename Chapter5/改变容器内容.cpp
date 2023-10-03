//
// Created by Momo on 2023/9/30.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

static void transform_in_use() {
    vector<int> v = {1, 2, 3, 4, 5};

    /**
     * @brief transform() 对容器范围内容进行一个改变
        * 4 个参数，前两个决定范围
        * 倒数第二个是输出迭代器，可以输出到屏幕或者保存到新的容器当中去
        * 最后一个参数可以接受一个函数或 lambda 对象，实现对元素的操作
     * */
    transform(v.begin(), v.end(),
              ostream_iterator<int>{cout, ", "},
              [](int i) { return i * i; });
}

int main() {
    return 0;
}
