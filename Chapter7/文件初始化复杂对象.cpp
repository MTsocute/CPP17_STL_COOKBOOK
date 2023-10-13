//
// Created by Momo on 2023/10/8.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

struct city {
    string name;
    size_t population;
    double latitude;
    double longitude;
};

/* 重载 >> 使得 istream_it 获取结构体类型的数据 */
istream &operator>>(istream &is, city &c) {
    is >> ws;   // 跳过开头空白部分，防止城市名被污染
    getline(is, c.name);    // 给城市名赋值
    // 给数据赋值
    is >> c.population >> c.latitude >> c.longitude;
    return is;
}

int main() {
    vector<city> l;
    ifstream ifs{"/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter7/data/city.txt"};
    if (ifs.is_open()) {
        // 使用 istream_it 获取外部数据填充到容器当中
        // 这里的 istream_it 重载了 对于 city 类型的 operator>>
        copy(istream_iterator<city>{ifs}, {}, back_inserter(l));

        for (const auto &[name, pop, lat, lon]: l) {
            cout << left << setw(15) << name
                 << " population=" << pop
                 << " lat=" << lat
                 << " lon=" << lon << '\n';
        }
    } else cout << "File Not Found!\n";

    ifs.close();

    return 0;
}