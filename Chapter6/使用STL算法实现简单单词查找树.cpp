//
// Created by Momo on 2023/10/4.
//

#include "使用STL算法实现简单单词查找树.h"


int main() {
    trie<string> t;

    t.insert({"hi", "how", "are", "you"});
    t.insert({"hi", "how", "i", "am", "great"});
//    t.insert({"what", "are", "you", "doing"});
//    t.insert({"i", "am", "watching", "a", "movie"});

    cout << "recorded sentences:\n";
    t.print();

    return 0;
}