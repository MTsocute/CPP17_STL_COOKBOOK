//
// Created by Momo on 2023/11/6.
//
#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;


int main(int argc, char **argv) {
    // 输入文件路径用于初始化
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <path>\n";
        return 1;
    }

    // filesystem::path 实例化一个文件路径对象
    const path dir = argv[1];   // 初始化一个文件路径对象

    // filesystem::exist 检查文件路径存在与否
    if (!exists(dir)) {
        cout << "Path " << dir << " does not exist.\n";
        return 1;
    }

    // filesystem::canonical 对路径标准化
    cout << canonical(dir).c_str() << '\n';

    return 0;
}