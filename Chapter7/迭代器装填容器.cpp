//
// Created by Momo on 2023/10/9.
//
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

struct meme {
    string description;
    size_t year;
};

using mymap = map<string, meme>;

/* 给结构体插入元素 */
istream & operator>>(istream & is, meme & m) {
    // is >> quoted()：添加双引号在字符串写入的字符串上
    return is >> quoted(m.description) >> m.year;
}

/* 插入 map 类型创建的 istream 函数*/
istream & operator>>(istream & is, pair<string, meme> & p) {
    // 注意这里的 p.second 是结构体
    // operator>> (istream & is, meme & m) 处理 meme 结构体
    return is >> quoted(p.first) >> p.second;
}

static void print(mymap & m) {
    for (const auto &[meme_name, meme_desc] : m) {
        const auto &[desc, year] = meme_desc;
        cout<< meme_name << " : " << desc << ", " << year << '\n';
    }
}


int main() {
    mymap m;
    ifstream ifs {"/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter7/data/memes.txt"};

    if (ifs.is_open()) {
        // 给 map 容器使用迭代器插入元素
        copy(istream_iterator<pair<string, meme>> {ifs},{}, inserter(m, end(m)));
        print(m);

        size_t len = 0;
        for (const auto & [k, v] : m) {
            if (v.description.size() > len)
                len = v.description.size();
        }

        cout << "\nThe longest length of meme is: " << len << endl;

    } else { cerr << "File Not Found!\n\a"; }

    return 0;
}