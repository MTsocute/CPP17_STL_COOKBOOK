//
// Created by Momo on 2023/9/14.
//

#include "setSTL操作.h"


int main() {
//    demo1();
    inserter_in_use();
//    copy_in_use();
    return 0;
}

void demo1() {
    std::set<std::string> s;

    // 使用 istream_iterator 从标准输入读取字符串
    std::istream_iterator<std::string> it(std::cin);
    std::istream_iterator<std::string> end;

    // 使用 inserter 包装 set，并使用 std::copy 填充
    std::copy(it, end, std::inserter(s, s.end()));

    // 打印 set 中的元素
    for (const auto &word: s)
        std::cout << word << ", ";
    std::cout << '\n';
}

void inserter_in_use() {
    std::vector<int> myVector;
    std::list<int> myList;

    /**
     * @brief inserter() 插入变量到 非关联容器中
     * 需要两个参数:
        * 1、需要插入元素的容器
        * 2、每次拆入容器的位置
     * 有返回值是一个迭代器，可以作为指针使用
     * */

    // 使用 std::inserter 插入元素到 vector 中
    std::inserter(myVector, myVector.begin()) = 42;
    std::inserter(myVector, myVector.end()) = 17;
    std::inserter(myVector, myVector.begin()) = 60;


    // 使用 std::inserter 插入元素到 list 中
    std::inserter(myList, myList.begin()) = 10;
    std::inserter(myList, myList.end()) = 42;
    std::inserter(myList, myList.begin()) = 50;


    // inserter() 返回迭代器，像指针一样插入元素
    auto insert_it = inserter(myVector, myVector.begin());

    *(insert_it) = 13000;


    // 打印 vector 中的元素
    for (const auto &element: myVector)
        std::cout << element << " ";
    std::cout << std::endl;

    // 打印 list 中的元素
//    for (const auto &element: myList)
//        std::cout << element << " ";
//    std::cout << std::endl;
}

void copy_in_use() {
    vector<int> source = {1, 2, 3};
    vector<int> destination = {4, 5, 6};

    // copy() 拷贝数据到本身或其他容器
//    copy(source.begin(), source.end(),
//         inserter(destination, destination.begin()));

//    copy(source.begin(), source.end(),
//         inserter(destination, destination.end()));

//    copy(source.begin(), source.end(), source.begin() + 2);

    show_data(source);
}