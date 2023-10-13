//
// Created by Momo on 2023/10/13.
//
#include <iostream>
#include <fstream>
#include <system_error>
#include <cstring>
#include <fmt/core.h>

using namespace std;


int main() {
    ifstream ifs;

    /**
     * 文件错误时，主动抛出异常
     * failbit：用于指示文件操作失败
     * badbit：文件流本身出问题，文件损坏之类的
     * */
    ifs.exceptions(std::ifstream::failbit | std::fstream::badbit);

    // 捕获异常
    try {
        // a flie but do not exist
        ifs.open("/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter7/data/fof.txt", ios_base::in);
        int i;
        ifs >> i;
        cout << fmt::format("We get the data i = {}\n", i);
    }
    // 捕获文件流相关的异常问题
    catch (ios_base::failure & e) {
        cout << "Caught Error: ";
        // errno: 区分处罚的异常是一个文件系统问题，还是一个格式解析问题
        // 返回值为 1 就是文件系统出了问题：找不到文件
        if (errno) {
            // strerror(): 将错误转换成字符串
            cout << "1: " << strerror(errno) << endl;
        }
        else {
            // catch 错误对象的 what() 成员函数，解释触发了那种类型的错误
            cout << "2: " << e.what() << endl;
        }
    }

    return 0;
}