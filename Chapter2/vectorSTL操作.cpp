//
// Created by Momo on 2023/9/11.
//

#include "vectorSTL操作.h"

// 使用 quick_remove_at O(1) 时间内删除元素
void demo1() {
    vector<int> v = {1, 2, 3, 4};
    quick_remove_at(v, find(v.begin(), v.end(), 2));

    show_number_vec(v);
}

vector<string> v{"some", "random", "words",
                 "without", "order", "aaa",
                 "yyy"};
void assert_in_use() {
    // 会输出错误位置，结束程序
    assert(30 == 20);
}

int main() {
//    delete_data_range();
//    remove_specific_number();
//    access_v_data_safely();
//    demo1();


    return 0;
}