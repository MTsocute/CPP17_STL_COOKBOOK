//
// Created by Momo on 2023/10/9.
//
#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <algorithm>

using namespace std;
using namespace std::string_literals;

string word_num(int i) {
    unordered_map<int, string> m{
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
            {5, "five"}, //...
    };
    const auto match(m.find(i));
    if (match == end(m)) { return "unknown"; }
    return match->second;
}

struct bork {
    int borks;

    bork(int i) : borks{i} {}

    void print(ostream &os) const {
        // fill_n(): 把指定数量的对象插入到容器当中去
        fill_n(ostream_iterator<string>{os, " "},
               borks, "bork!"s);
    }
};

// 重载 << ，我们可以顺序使用 cout << bork
ostream &operator<<(ostream &os, const bork &b) {
    b.print(os);
    return os;
}

static void os_it(const vector<int> & v) {
    ostream_iterator<int> oit {cout, " -> "};

    for (int i : v) { *oit = i; }
    std::cout << "End\n"s;
}

static void os_it_2(const vector<int> & v) {
    ostream_iterator<int> oit {cout, " -> "};
    // copy 配合 os_it 打印容器
    // copy() 对迭代器，相当于 *it = value，操作交给迭代器
    copy(v.begin(), v.end(), oit);
    std::cout << "End\n"s;
}

static void os_it_3(const vector<int> & v) {
    ostream_iterator<int> oit {cout, " -> "};
    // transform 配合 os_it 打印
    // word_num 会把 int -> string 然后交给 os_it 打印
    transform(v.begin(), v.end(),
              ostream_iterator<string> {cout, " -> "}, word_num);
    std::cout << "End\n"s;
}

int main() {
    bork b(10);
//    b.print(std::cout);
//    cout << b;

    const vector<int> v {1, 2, 3, 4, 5};
    os_it(v);

    os_it_3(v);

//    copy(v.begin(), v.end(), ostream_iterator<bork> {cout, "\n"});

    auto bork_print = [](int x){
        cout << bork(x) << endl;
    };

    // for_each(): 给某个范围的值都进行某一个函数操作
    for_each(v.begin(), v.end(), bork_print);

    return 0;
}