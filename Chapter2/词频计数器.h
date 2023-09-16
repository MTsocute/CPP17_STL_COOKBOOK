//
// Created by Momo on 2023/9/15.
//

#ifndef STL_词频计数器_H
#define STL_词频计数器_H

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

vector<string> s = {
        "momo",
        "life",
        "here",
        ",dadadue;",
        "dadadue,"
};

void sth_about_string_func();

string filter_punctuation(const string &s);

void show_data_of_dc(const int & max_word_len, const vector<pair<string, size_t>> & word_counts);

void show_data_of_dc(const int & max_word_len, const vector<pair<string, size_t>> & word_counts) {
    cout << "# " << setw(max_word_len) << "<WORD>" << " #<COUNT>\n";
    for (const auto &[word, count]: word_counts) {
        cout << setw(max_word_len + 2) << word << " #" << count << '\n';
    }
}

void sth_about_string_func() {
    string demo1 = "ello";

    // string.find_first_not_of(str)：查找第一个不存在于 str 中字符的位置
    size_t pos = demo1.find_first_not_of("aeiou");
    // string.found_last_not_of(str): 查找最后一个不存在 str 中字符的位置
    size_t pos2 = demo1.find_last_not_of("aeiou");

    cout << "The first character but not vowel is at: " << pos << endl
         << "The first character but not vowel is at: " << pos2;
    // string.substr(begin, end): 获取 [start, end) 之间的子字符串
    cout << "New substr is: " << demo1.substr(pos, pos2 - pos + 1) << endl;
}

string filter_punctuation(const string &s) {
    const char *forbidden{".,:; "};
    const auto idx_start
            (s.find_first_not_of(forbidden));
    const auto idx_end
            (s.find_last_not_of(forbidden));
    return s.substr(idx_start, idx_end - idx_start + 1);
}

#endif //STL_词频计数器_H
