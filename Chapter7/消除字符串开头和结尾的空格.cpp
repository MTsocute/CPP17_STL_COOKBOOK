//
// Created by Momo on 2023/10/6.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string trim_whitespace_surrounding(const string &s) {
    const char whitespace[] {" \t\n"};
    const auto first = s.find_first_not_of(whitespace);

    // 找不到一个非空白的字符，说明，整个字符串为空
    if (first == string::npos) return {};

    const auto last = s.find_last_not_of(whitespace);

    // npos 代表的意思是：no position 取 n 和 pos
    if (last == string::npos) return {};

    return s.substr(first, (last - first + 1));
}

int main() {
    string s {" \t\n string surrounded by ugly"
              " whitespace \t\n "};
    cout << s;

    cout << "{" << trim_whitespace_surrounding(s) << "}\n";

    return 0;
}