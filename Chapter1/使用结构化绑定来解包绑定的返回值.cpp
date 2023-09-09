#include <iostream>
#include <iomanip>
#include <utility>
#include <map>

using namespace std;

struct employee {
    unsigned int id;
    std::string name;
    unsigned int salary;
};


// 定义一个函数来计算商和余数，并返回一个 std::pair 对象
std::pair<int, int> divider_remainder(int dividend, int divisor) // --> 这是一个函数哦
{
    int fraction = dividend / divisor;
    int remainder = dividend % divisor;
    return std::make_pair(fraction, remainder);
}

// std::pair 基础用法
void pair_base() {
    // 调用 divider_remainder 函数来计算商和余数
    auto result = divider_remainder(16, 3);

    // 使用结构化绑定来解包结果
    auto [fraction, remainder] = result;

    cout << "16 / 3 is " << fraction
         << " with a remainder of " << remainder << endl;
}

// 所有初始化 pair 的方法
void ini_pair() {
    // 1. 直接初始化
    std::pair<int, std::string> myPair1(42, "Hello, C++");

    // 2. make_pair() 函数初始化
    auto myPair2 = std::make_pair(42, "Hello, C++");

    // 3. {} 初始化
    std::pair<int, std::string> myPair3 = {42, "Hello, C++"};

    // 4. 成员函数初始化
    std::pair<int, std::string> myPair;
    myPair.first = 42;
    myPair.second = "Hello, C++";
}


// std::tuple 初始化
void ini_tuple() {
    // 1. 直接初始化
    std::tuple<int, std::string, double> myTuple1(42, "Hello, C++", 3.14159);

    // 2. make_tuple() 函数初始化
    auto myTuple2 = make_tuple("momo", true, 1141514);

    // 3. forward_as_tuple 初始化
    int intValue = 42;
    std::string stringValue = "Hello, C++";
    double doubleValue = 3.14159;

    auto myTuple = std::forward_as_tuple(intValue, stringValue, doubleValue);
}

// 使用结构化绑定来解元组
void unpack_tuple() {
    auto myTuple2 = make_tuple("momo", true, 1141514);

    auto [d1, d2, d3] = myTuple2;

    cout << d1 << " " << std::boolalpha << d2 << " " << d3 << endl;
    cout << std::noboolalpha << endl;
}

// 结构化绑定可以来解包结构体
void unpack_struct() {
    vector<employee> e;
    employee e1 = {.name = "momo1", .id=123, .salary=1151234};
    employee e2 = {.name = "momo2", .id=321, .salary=1151234};

    e.push_back(e1);
    e.push_back(e2);

    // for( : ) 遍历使用 & 减少赋值，避免不必要内存消耗
    for (const auto &[id, name, salary]: e)    // 利用 [] 解结构体的包
        cout << setw(10) << "id = " << id << " "
             << "name = " << name << " "
             << "salary = " << salary << endl;
}

// 解 std::map 的包
void unpack_map() {
    std::map<std::string, size_t> animal_population{
            {"humans",   7000000000},
            {"chickens", 17863376000},
            {"camels",   24246291},
            {"sheep",    1086881528},
    };

    for (const auto &[key, value]: animal_population) {
        cout << setw(20) << std::left << "key = " << key << endl;
        cout << setw(30) << "value = " << value << endl;
    }
}

int main() {
//    unpack_tuple();

//    unpack_struct();

    unpack_map();
    return 0;
}
