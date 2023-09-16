//
// Created by Momo on 2023/9/15.
//

#include "词频计数器.h"

int main() {
//    sth_about_string_func();
    map<string, size_t> words;
    int max_word_len{0};

    for (const auto &str: s) {
        auto &&filtered = filter_punctuation(str);
        max_word_len =
                max<int>(max_word_len, static_cast<int>(filtered.length()));
        // ++words[filtered];
        auto [it, success] = words.try_emplace(filtered, 1);
        if (!success) it->second++;
    }

    // 存放字典键-值的的容器
    vector<pair<string, size_t>> word_counts;
    // vector.reserve(size)：预留足够的空间，避免不必要的重新分配
    word_counts.reserve(words.size());

    //TODO:: 把 map 的 k-v 利用解包存放到 pair 容器中
    move(words.begin(), words.end(),
         back_inserter(word_counts));

    // 自定义谓词的 sort() 排序
    sort(begin(word_counts), end(word_counts),
         [](const auto &a, const auto &b)
         { return a.second > b.second; });

    show_data_of_dc(max_word_len, word_counts);

    return 0;
}