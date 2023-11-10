//
// Created by Momo on 2023/11/6.
//
#include <filesystem>
#include <iostream>

using namespace std;
using namespace filesystem;

static path abs_p{"/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter10/data/foobar.txt"};
static path p{"../Chapter10/data/foobar.txt"};

static void demo1() {
    // filesystem::current_path() 输出可执行文件当前说在的文件路径
    cout << "current_path    : " << current_path() << '\n'
         // filesystem::absolute(相对路径) 把一个相对路径变成绝对路径
         << "absolute_path   : " << absolute(p) << '\n';
}

static void demo2() {
    // path 对象对 / 进行了重载，有助于我们连接文件或路径
    cout << path{"filesystem"} / "testfile.txt" << endl;
}

static void demo3() {
    // 使用 canonical 创建一个绝对路径
    auto canonicalPath = canonical(p);

    cout << "Relative Path: " << p << '\n';
    cout << "Canonical Path: " << canonicalPath << '\n';
}

static void demo4() {
    cout << "equivalence: "
    // filesystem::equivalent() 规范化两个路径，判断是不是同一个路径
         << equivalent("../Chapter10/data/foobar.txt",
                       "../Chapter10/data/../data/foobar.txt") << '\n';
}

int main() {
//    demo1();
//    demo2();
//    demo3();
//    demo4();

    return 0;
}