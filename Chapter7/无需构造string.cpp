//
// Created by Momo on 2023/10/7.
//
#include <iostream>
#include <string_view>

using namespace std;

void print(string_view v) {
    const char arr[] = {" \n\t"};
    const auto word_begin = v.find_first_not_of(arr);

    // string_view.remove_prefix()：删除字符串前指定个数的前 n 个字符
    v.remove_prefix(min(word_begin, v.size()));

    const auto word_end = v.find_last_not_of(arr);

    if (word_end != string::npos)
        // string.remove_suffix()：删除字符串指定数量的后 n 个字符
        v.remove_suffix(v.size() - word_end - 1);

    cout << "length: " << v.length() << " [" << v << "]\n";
}

int main() {
    print(" life is fucking joke and movie! ");
    print(" \t\n foobar \n \t ");
    print("an std::string_view literal"sv);
    print("an std::string instance"s);
    return 0;
}