//
// Created by Momo on 2023/10/18.
//

#include <iostream>
#include <chrono>
#include <ratio>
#include <cmath>
#include <iomanip>
#include <optional>
#include <fmt/core.h>

using namespace std;
// using namespace chrono;


// chrono::duration --> 用于表示所用时间的长度
using seconds = chrono::duration<double>;   // 秒
/* 剩下两个部分会自动实现单位的转换 */
using milliseconds = chrono::duration<double,
        ratio_multiply<chrono::seconds::period, milli>>;  // 毫秒
using microseconds = chrono::duration<double,
        ratio_multiply<chrono::seconds::period, micro>>;  // 微秒

static pair<string, seconds> get_input() {
    // chrono::steady_clock::now() 记录当前时间
    string s;
    const auto begin = chrono::steady_clock::now();     // 记录开始时间

    if (!(cin >> s))
        return {{},
                {}};

    return {s, chrono::steady_clock::now() - begin};
}

static void printTimeDurations(seconds diff) {
    cout << fmt::format("Bravo. You did it in:\n"
                        "{:>12.2f} seconds.\n"
                        "{:>12.2f} milliseconds.\n"
                        "{:>12.2f} microseconds.\n",
            // 有 using 的话，会简化不少工作量
            // duration<double, milli>(diff).count()
            // duration<double, micro>(diff).count())
            // chrono::duration<> .count()：输出对应的时间
                        diff.count(), milliseconds(diff).count(), microseconds(diff).count());
}

int main() {
    while (true) {
        cout << "Please type the word \"C++17\" as"
                " fast as you can.\n> ";
        const auto &&[user_input, diff] = get_input();

        if (user_input.empty())
            break;

        if (user_input == "cpp17") {
            printTimeDurations(diff);
            break;
        } else
            cout << "Sorry, your input does not match. You may try again.\n";
    }

    return 0;
}
