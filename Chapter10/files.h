//
// Created by Momo on 2023/11/8.
//

#ifndef STL_FILES_H
#define STL_FILES_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <vector>
#include <filesystem>

using namespace std;
using namespace filesystem;

// file_status 是 status() 初始化对象的类型
static tuple<path, file_status, size_t>
file_info(const directory_entry &entry) {
    // status(directory_entry 对象)：返回一个文件或目录的详细信息
    const auto fs = status(entry);
    return {entry.path(),
            fs, // 返回 status 实例对象
            // is_regular_file(status 对象): 判断文件是不是常见类型的文件
            is_regular_file(fs) ? file_size(entry.path()) : 0u};
}

// 根据文件类型来返回不同的字符
static char type_char(const file_status &fs) {
    // 判断文件类型的函数集合
    if (is_directory(fs)) { return 'd'; }
    else if (is_symlink(fs)) { return 'l'; }
    else if (is_character_file(fs)) { return 'c'; }
    else if (is_block_file(fs)) { return 'b'; }
    else if (is_fifo(fs)) { return 'p'; }
    else if (is_socket(fs)) { return 's'; }
    else if (is_other(fs)) { return 'o'; }
    else if (is_regular_file(fs)) { return 'f'; }
    return '?';
}

// 判断文件的权限
static string rwx(perms p) {    // perms 一个类内的 enum 用于判断文件具有什么读写属性
    // 获取两个参数，一个用于判断具体用户是否有权限，有权限用另一个参数作为返回值，否则返回 -
    auto check = [p](perms bit, char c) {
        // perms::none：没有权限
        return (p & bit) == perms::none ? '-' : c;
    };

    // 判断不同用户具有的读写属性
    return {check(perms::owner_read, 'r'),
            check(perms::owner_write, 'w'),
            check(perms::owner_exec, 'x'),
            check(perms::group_read, 'r'),
            check(perms::group_write, 'w'),
            check(perms::group_exec, 'x'),
            check(perms::others_read, 'r'),
            check(perms::others_write, 'w'),
            check(perms::others_exec, 'x')};
}

// 根据不同文件大小输出文件
static string size_string(size_t size) {
    stringstream ss;
    if (size >= 1000000000) ss << (size / 1000000000) << 'G';
    else if (size >= 1000000) ss << (size / 1000000) << 'M';
    else if (size >= 1000) ss << (size / 1000) << 'K';
    else { ss << size << 'B'; }
    return ss.str();
}

static void print_v_info(const vector<tuple<path, file_status, size_t>> & items) {
    for (const auto &[path, status, size]: items) {
        cout << type_char(status) << ": " << rwx(status.permissions()) << "  "
             << setw(4) << right << size_string(size) << "  "
             << path.filename().c_str() << '\n';
    }
}

#endif //STL_FILES_H
