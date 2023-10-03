//
// Created by Momo on 2023/10/2.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;


// 辅助函数，用于打印查找算法所范围的位置，从而输出子字符串
template<typename Itr>
static void print(Itr it, size_t chars) {
    copy_n(it, chars, ostream_iterator<char>{cout});
    cout << '\n';
}

const string long_string{"Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod"};
const string needle{"elitr"};

/* search() 在字符串中寻找子串 */

static void demo1() {
    auto match =
            // 接受子串范围的寻找
            search(begin(long_string), end(long_string),
                   begin(needle), end(needle));
    print(match, 5);
}

static void demo2() {
    auto match =
            // default_search{}: 作用更大范围的字符串子串查找
            search(begin(long_string), end(long_string),
                   default_searcher{begin(needle), end(needle)});
    print(match, 5);
}

static void demo3() {
    auto match =
            // boyer_moore_searcher{} : 更加快速的子串查找
            search(begin(long_string), end(long_string),
                   boyer_moore_searcher{begin(needle), end(needle)});
    print(match, 5);
}

static void demo4() {
    auto match =
            // boyer_moore_xxx{}: 更加稳定的快速子串查找
            search(begin(long_string), end(long_string),
                   boyer_moore_horspool_searcher{begin(needle), end(needle)});
    print(match, 5);
}

int main() {
    demo1();
    demo2();
    demo3();
    demo4();
    return 0;
}