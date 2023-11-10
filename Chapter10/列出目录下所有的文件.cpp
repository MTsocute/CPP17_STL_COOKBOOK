//
// Created by Momo on 2023/11/8.
//
#include "files.h"

namespace fs = std::filesystem;

// 获取文件信息
static void demo1() {
    // 指定文件或目录的路径
    fs::path filePath("/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter10/data/foobar.txt");

    // 使用directory_entry对象创建文件信息的三元组
    // directory_entry(path 对象) 来初始化
    auto fileInfo = file_info(fs::directory_entry(filePath));

    // 分别获取路径、文件状态和文件大小
    fs::path path = std::get<0>(fileInfo);
    fs::file_status fileStatus = std::get<1>(fileInfo); // status 对象，我们就不具体使用了
    size_t fileSize = std::get<2>(fileInfo);

    // 打印文件信息
    std::cout << "Path: " << path << std::endl;
    std::cout << "File Type: " << type_char(fileStatus) << std::endl;
    std::cout << "File Size: " << fileSize << " bytes" << std::endl;
}

static void demo2() {
    fs::path filePath("/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter10/data/foobar.txt");
    auto fileStatus = status(filePath);

    // status 对象.permission()： 返回一个 enum 存储各项用户的读写属性
    cout << rwx(fileStatus.permissions()) << endl;

    cout << "Size:" << size_string(file_size(filePath)) << endl;
}

int main() {
//    demo1();
//    demo2();

    // 使用文件信息来填充容器
    vector<tuple<path, file_status, size_t>> items;
    vector<tuple<path, file_status, size_t>> items2;

    // 指定一个文件夹路径
    const fs::path dir{"/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter8"};

    // 遍历文件夹下每一个文件
    transform(    // directory_it: 迭代一个路径下的所有文件，并返回一个 directory_entry 对象
            directory_iterator{dir}, {},
            back_inserter(items), file_info); // file_info 是我们自己的函数

    // 我们可以使用 for 循环来平替 transform 遍历文件夹下的文件
    for (const auto & e: directory_iterator {dir}) {
        items2.push_back(file_info(e));
    }

    print_v_info(items2);

    return 0;
}
