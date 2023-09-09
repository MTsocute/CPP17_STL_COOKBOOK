//
// Created by Momo on 2023/9/8.
//

#include <iostream>
#include <map>

using namespace std;

void variable_in_bracket() {
    std::map<std::string, size_t> animal_population{
            {"humans",   7000000000},
            {"chickens", 17863376000},
            {"camels",   24246291},
            {"sheep",    1086881528},
    };

    // map 的 .find() 成员函数，是一个会自动迭代的迭代器，用于查找值
    auto it = animal_population.find("peach");

    if (it != animal_population.end())
        cout << "Done and the Value: " << it->second << endl;
    else cout << "Data Not Found \n";

    // 我们可以在 if 的() 中声明变量，减少书写
    if (auto it = animal_population.find("sheep"); it != animal_population.end())
        cout << "Done and the Value: " << it->second << endl;
    else cout << "Data Not Found \n";


    // 我们也可以在 switch () 声明变量，减少书写
    switch (char c = static_cast<char> (cin.get()); c) {
        case 'a':
            cout << "a\n";
            break;
        case 'q':
            cout << "quit\n";
            break;
            // switch ... case 捕获范围数
        case '0'...'9':
            cout << "this is number\n";
            break;
        default:
            std::cout << "unknown input: " << c << '\n';
    }
}

void demo() {
    char d1[20], d2[20];
    string d;

    cin.get(d1, 20);    // --> '\n' in buffer

    while ((cin.get()) != '\n') continue;

    cin.getline(d2, 20);

    cout << "d1 = " << d1 << endl << "d2 = " << d2 << endl;
}


int main() {
//    variable_in_bracket();

    demo();

    return 0;
}