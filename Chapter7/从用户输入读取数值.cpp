//
// Created by Momo on 2023/10/7.
//
#include <iostream>
using namespace std;

int main() {
    cout << "Please Enter two numbers:\n> ";
    int x;
    double y;

    if (std::cin >> x >> y)
        cout << "You entered: " << x <<
        " and " << y << '\n';
    else {
        cout << "Oh no, that did not go well!\n";
        cin.clear();
        // cin.ignore(): 忽略掉\n之前最大的限度的字符
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        cout << "now please enter some "
                "comma-separated names:\n> ";
        // getline() 获取字符串输入，使用 , 作为分隔符号
        // cin >> ws 赋值给 s 之前，清除多余的 space
        for (string s; getline(cin >> ws, s, ',');) {
            if (s.empty()) break;
            cout << "name: \"" << s << "\"\n";
        }
    }

    return 0;
}
