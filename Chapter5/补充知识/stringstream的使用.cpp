//
// Created by Momo on 2023/9/30.
//
#include <sstream>
#include <iostream>

using namespace std;

void s_base() {
    // 使用 字符串流对象，存储字符串在数据流中
    std::stringstream ss;
    int num = 42;
    double pi = 3.14159;
    std::string text = "Hello, World!";

    // << 存储字符串到 stringsteam 流中
    ss << "The number is: " << num
       << ", Pi is approximately: "
       << pi << ", and the text is: "
       << text << endl;

    // stringstream.str()：获取流中的内容
    cout << ss.str();


    std::string numStr = "12345";
    int extractedNum;
    ss.clear(); // stringstream.clear(): 清除stringstream状态

    ss.str(numStr); // 设置stringstream的内容为numStr

    // stringstream >> 从流中输出对应数据赋给变量
    ss >> extractedNum;

    // stringstream.fail()：检测流是否发生了操作错误
    if (!ss.fail())
        std::cout << "Extracted number: " << extractedNum << std::endl;
    else
        std::cout << "Extraction failed!" << std::endl;
}

int main() {
    s_base();
    
    return 0;
}