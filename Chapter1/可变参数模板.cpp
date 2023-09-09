//
// Created by Momo on 2023/9/8.
//
#include <iostream>

using namespace std;


// 递归展开参数包并打印参数
void printArgs() {
    std::cout << std::endl;  // 打印换行符表示结束
}

// 可变参数模版的基本使用方法
template<typename T, typename... Args>
// Args... 声明类型参数包
void printArgs(T first, Args... args) {
    std::cout << first << " (" << sizeof...(args) << ") ";
    printArgs(args...);  // 递归展开参数包
}

// 我们要写一个同名函数作为递归的结束条件，这个很麻烦
// 我们可以利用 sizeof ..(param pack) 当参数列表 =0 的时候，作为递归的终止条件
template<typename T, typename... Args>
void myPrint(T &&data, Args &&... args)  // 使用 && 可以避免拷贝临时变量
{
    cout << data << " (" << sizeof...(args) << ") ";
    // constexpr-if 作为可变参数模板的递归终止条件
    if constexpr (sizeof...(args) > 0) myPrint(args...);
    else cout << endl;
}

// 稍微了解的 Fold 表达式
template<typename ... T>
auto myAdd(T... args)-> std::common_type_t<T ...>   // common_type_t: 返回可变模版参数中最合适的类型
{   // 当 op 和 参数列表 结合结合起来的时候会自动计算
//    return (... + args);    // equals to (((arg1 + arg2) + arg3) + ... + argN)
    return (args + ...);    // equals to (arg1 + ... + (argN-2 + (argN-1 + argN)))
}

// 利用 Fold Expression 再次简化输出形式
template<typename... Ts>
void myprint2(Ts ... args) {
    (cout << ... << args) << " " << endl;
}

int main() {
//    printArgs(1, "Hello", 3.14);
//    myPrint(1, "momo", 3.14);

    cout << "Ret of myAdd: " <<  myAdd(1, 1.4, 12) << endl;

    myprint2(10,20,30,"momo","super", 114.514);

    return 0;
}