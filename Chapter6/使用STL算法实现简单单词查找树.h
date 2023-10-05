//
// Created by Momo on 2023/10/4.
//

#ifndef STL_使用STL算法实现简单单词查找树_H
#define STL_使用STL算法实现简单单词查找树_H

#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>

using namespace std;

/* 前缀树的实现 */
template<class T>
class trie {
private:
    map<T, trie> tries; // T 是数据的类型，trie 存下一个节点
public:
    // 用户提供迭代器，实现插入元素
    template<class It>
    void insert(It it, It end_it);

    // 用户提供容器，实现插入元素
    template<class C>
    void insert(const C &container);

    // 用户提供 ini_list, 实现元素插入
    void insert(const initializer_list<T> &ini_list);

    // 查看 tries 中有什么
    void print(vector<T> &v) const;
    void print() const;
};

template<class T>
void trie<T>::print() const {
    vector<T> v;
    print(v);
}

template<class T>
// 深度优先遍历(DFS)：非常精彩绝伦的代码
void trie<T>::print(vector<T> &v) const {
    // 当树为空的时候，打印内容
    if (this->tries.empty()) {
        copy(v.begin(), v.end(), ostream_iterator<T>{cout, " "});
        cout << endl;
    }
    // 注意这个 for 是整个递归的 for，每一层的叶子都进行，不断往下
    // 特别适合多分支遍历到底的模式
    for (const auto &p: tries) {
        v.push_back(p.first);
        p.second.print(v);
        v.pop_back();
    }
}

template<class T>
void trie<T>::insert(const initializer_list<T> &ini_list) {
    insert(ini_list.begin(), ini_list.end());
}

template<class T>
template<class C>
void trie<T>::insert(const C &container) {
    // 转交给迭代代码实现
    this->insert(container.begin(), container.end());
}

template<class T>
template<class It>
void trie<T>::insert(It it, It end_it) {
    // 不到容器的末尾，就不停止
    if (it == end_it) return;
    // 创建一个新的 下一个数据为键，值为空的 trie 节点
    // 这里是一个递归，建立起了最后一层和上一层的联系，不断上走，建立联系
    this->tries[*it].insert(std::next(it), end_it);
}

#endif //STL_使用STL算法实现简单单词查找树_H
