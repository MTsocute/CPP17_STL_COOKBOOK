//
// Created by Momo on 2023/10/3.
//
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <string>

using namespace std;

using dict_pattern = pair<string, string>;

/* 从这里看的出来，就是两个容器中选择比较小的先排前面 */
static void merge_in_use1() {
    std::vector<int> v1 = {111, 310, 120};
    std::vector<int> v2 = {4, 100, 112};
    std::vector<int> result(6);

    // 使用 merge() 合并[非关联]容器
    std::merge(v1.begin(), v1.end(),
               v2.begin(), v2.end(), result.begin());

    for (int num: result) std::cout << num << ' ';
}

/* 注意如果正好适合交错大小的数据，merge 后会按顺序排好的*/
static void merge_in_use2() {
    std::list<int> v1 = {1, 3, 5};
    std::list<int> v2 = {2, 4, 6};
    std::list<int> result{};

    merge(v1.begin(), v1.end(),
          v2.begin(), v2.end(), back_inserter(result));

    for (const auto &num: result) cout << num << " ";
    cout << endl;
}

int main() {
    merge_in_use1();
    return 0;
}