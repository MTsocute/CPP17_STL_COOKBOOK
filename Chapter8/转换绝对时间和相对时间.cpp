//
// Created by Momo on 2023/10/19.
//

#include <fmt/core.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

// 创建天的时间单位模版
using days = chrono::duration<chrono::hours::rep,
        ratio_multiply<chrono::hours::period, ratio<24>>>;

using mymonth = chrono::duration<chrono::days::rep,
        ratio_multiply<chrono::days::period, ratio<30>>>;


ostream &operator<<(ostream &os, const struct tm *&local_time) {
    printf("Year: %d\n", local_time->tm_year + 1900);
    printf("Month: %d\n", local_time->tm_mon + 1);
    printf("Day: %d\n", local_time->tm_mday);
    printf("Hour: %d\n", local_time->tm_hour);
    printf("Minute: %d\n", local_time->tm_min);
    printf("Second: %d\n", local_time->tm_sec);
    return os;
}

static void demo() {
    auto now = chrono::system_clock::now();
    const auto tt = chrono::system_clock::to_time_t(now);
    const auto tm = localtime(&tt);
    /* 输出一下时间结构体的内容 */
    std::cout << tm;
    cout << put_time(std::move(tm), "%c") << endl;
}

ostream &operator<<(ostream &os, const chrono::time_point<chrono::system_clock> &t) {
    // chrono::system_clock::to_time_t()：转换为 time_t 时间戳
    const auto tt = chrono::system_clock::to_time_t(t);
    // localtime() 转变时间戳为结构体时间结构体
    const auto loct = std::localtime(&tt);
    // put_time(): 整理 time structure 结构为包含时间很多信息的字符串
    return os << put_time(loct, "%c");
}

/* 创建属于 days 类型的字面量 */
constexpr days operator ""_days(unsigned long long int d) {
    return days{d};
}

int main() {
//    demo();
    chrono::time_point<chrono::system_clock> begin;
    // chrono::system_clock::now() 返回当前的时间 << endl;
    auto now = chrono::system_clock::now();

//    cout << ts << endl;
//    cout << "The current data and time is: " << now << endl;

    // 创建一个 12 小时的时间单位
//    chrono::hours hour_12{12};
//    cout << begin << endl;12
//    cout << (begin + hour_12) << endl;

    // 创建一个 2 个月的时间单位
//    auto month_2 = mymonth {2};
//    cout << (begin + month_2) << endl;

    // 使用时间字符字面量
    cout << (begin + 12h + 49min + 33s) << endl;

    return 0;
}