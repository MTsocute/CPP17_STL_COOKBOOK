//
// Created by Momo on 2023/10/8.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

template<class T>
// 对输入流，统计词的数量
size_t wordCount1(T & is) {
    // 简化的使用 istream_iterator
    return distance(istream_iterator<string>{is}, {});
}

// 复杂版本的实现
template <class T>
size_t wordCount2(T & is){
    istream_iterator<string> start(is);

    size_t data = 0;
    // 没有输入任何参数的 istream_it 表示输入流的末尾位置
    while (start != istream_iterator<string> {}) {
        cout << "Read: " << *start << endl;
        start ++, data ++;
    }
    return data;
}

int main(int argc, char ** argv) {
    size_t wc;
    if (argc == 2) {
        cout << "command we input: " <<  argv[1] << endl;
        ifstream ifs { argv[1] };
        wc = wordCount1(ifs);
    }
    else wc = wordCount2(cin);

    cout << "There are " << wc << " words\n";
    return 0;
}