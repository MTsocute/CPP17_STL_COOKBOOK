//
// Created by Momo on 2023/9/11.
//

#ifndef STL_VECTORSTL操作_H
#define STL_VECTORSTL操作_H

#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>
#include <algorithm>

using namespace std;

template<typename T>
void show_number_vec(const vector<T> &v) {
    for (const auto &num: v)
        cout << num << " ";
    cout << endl;
}

// 删除 vector 范围内指定的数
void delete_data_range() {
    vector<int> v = {1, 3, 45, 6, 7, 7, 32, 1, 4, 5};

    cout << "original data: \n";
    show_number_vec(v);

    // 移动所有的 7 到数组的末尾
    const auto new_end =
            std::remove(v.begin(), v.end(), 7);

    show_number_vec(v);

    // 删除 v 中所有的 7
    v.erase(new_end, v.end());

    // 重新调整 vector 到合适大小
    v.shrink_to_fit();

//    show_number_vec(v);
}

// 利用 lambda 函数删除某个特征的值
void remove_specific_number() {
    // 谓词函数
    const auto odd =
            [](int i) { return i % 2 != 0; };
    vector<int> v = {1, 3, 45, 6, 7, 7, 32, 1, 4, 5};
    // 选择性的删除数值
    const auto new_end =
            std::remove_if(v.begin(), v.end(), odd);

    v.erase(new_end, v.end());

    show_number_vec(v);
}

// 快速删除函数的实现 O(1) 时间复杂度
// 这个就是取最后一个覆盖当前位置，然后删除最后一个元素，不保证顺序
template<typename T>
void quick_remove_at(std::vector<T> &v,
     typename std::vector<T>::iterator it) { // 显式的告诉编译器 it 是迭代器
    if (it != std::end(v)) {
        // v.back() 返回临时变量，我们利用 move 避免 = 的拷贝
        *it = std::move(v.back());
        v.pop_back();
        v.shrink_to_fit();
    }
}

// 安全的访问 vector 中的元素
void access_v_data_safely() {
    const size_t num = 1000;
    vector<int> v (num, 123);

    // 使用 [] 访问 out of index 时候，不报错
    cout << v[num + 10] << endl;

    // 使用 vector.at() 安全的访问容器
    try {
        cout << v.at(num + 123) << endl;
    } catch (const std::out_of_range & e) {
        cerr << "Out of range!!\n";
    }
}

// vector 实例排序
void vector_instance_sort() {

}

// 实现新插入数，仍保持数组的排序
template<class T>
void insert_in_order(vector<T> & v, const T && word) {
    try { assert(false == std::is_sorted(v.begin(), v.end())); }
    catch (const exception & e){
        std::sort(v.begin(), v.end());
    }

    // 寻找 x > 刚好大于或等于容器值的那个位置
    const auto new_ins_pos2 = v.lower_bound(word);  // 使用成员函数的 lower_bound()
    const auto new_ins_pos = lower_bound(v.begin(), v.end(), word);

    // vector.insert() 在指定位置插入值，其他后移
    v.insert(new_ins_pos, word);
}

#endif //STL_VECTORSTL操作_H
