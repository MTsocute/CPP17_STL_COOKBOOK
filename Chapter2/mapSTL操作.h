//
// Created by Momo on 2023/9/12.
//

#ifndef STL_MAPSTL操作_H
#define STL_MAPSTL操作_H

#include <iostream>
#include <functional>
#include <list>
#include <map>
#include <unordered_map>


using namespace std;

struct billionaire {
    string name;
    double dollars;
    string country;
};

// 存储某个国家
static map<string, pair<const billionaire, size_t>> m;

struct coord {
    int x;
    int y;
};


static list<billionaire> billionaires{
        {"Bill Gates",          86.0, "USA"},
        {"Warren Buffet",       75.6, "USA"},
        {"Jeff Bezos",          72.8, "USA"},
        {"Amancio Ortega",      71.3, "Spain"},
        {"Mark Zuckerberg",     56.0, "USA"},
        {"Carlos Slim",         54.5, "Mexico"},
        {"Bernard Arnault",     41.5, "France"},
        {"Liliane Bettencourt", 39.5, "France"},
        {"Wang Jianlin",        31.3, "China"},
        {"Li Ka-shing",         31.2, "Hong Kong"}
};

// try_emplace() 的使用
void try_emplace_in_use();

void demo1();

void demo2();

template<class T, class Y>
static void show_map(std::map<T, Y> &map) {
    for (const auto &[key, value]: map)
        std::cout << "\"" << key << "\": " << value << ", ";
    std::cout << '\n';
}

// 修改 map 的 k-v
void mod_map();


// hash 的相等性比较
bool operator==(const coord &l, const coord &r) {
    return l.x == r.x && l.y == r.y;
}

namespace std {
    // std 本来就有一个 hash() 的模板函数，我们定义自己的类型的 hash 返回值
    template<>
    struct hash<coord> {
        using argument_type = coord;
        using result_type = size_t;

        result_type operator()(const argument_type &c) const {
            return static_cast<result_type>(c.x) + static_cast<result_type>(c.y);
        }
    };
}

void demo3();

#endif //STL_MAPSTL操作_H
