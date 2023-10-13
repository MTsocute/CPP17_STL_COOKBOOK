//
// Created by Momo on 2023/10/10.
//
#include <iostream>
#include <fstream>

using namespace std;

class redirect_cout_region {
private:
    using buftype = decltype(cout.rdbuf());  // 内部流指针类型声明
    ofstream ofs;   // 输出内容到的文件夹位置
    buftype buf_backup; // 指向流向内部缓冲区的指针

public:
    /* 类变量的申明顺序就是构造函数成员列表初始化的顺序
     * 按照我们的逻辑，我们 buf_backup 是为了指向 ofs，以便输入数据
     * 所以我们要先创建 ofs 才能确定 buf_backup 的指向
     * 但是实际上，我们列表初始化的顺序，和其列表变量前后无关
     * 他和变量声明时候的先后顺序有关
     * */
    explicit redirect_cout_region(const string &filename) : ofs{filename},
    // cout.rdbuf()：返回一个当前缓冲区的指针，如果有参数的话，可以定向到别的缓冲区上
    // TODO:: 所以这里要注意了，他是返回当前的 cout 给 buf_backup，然后使用参数指定自己到 ofs buf 位置上
    buf_backup{cout.rdbuf(ofs.rdbuf())} {}

    // 默认构造函数
    // ofs 没有对象，所以输出内容会指向空输出
    redirect_cout_region() : ofs{}, buf_backup{cout.rdbuf(ofs.rdbuf())} {}

    // 析构函数对于重定向会进行恢复，不再指向文件
//    ~redirect_cout_region() { cout.rdbuf(); }
    ~redirect_cout_region() { cout.rdbuf(buf_backup); }

};

void my_output_heavy_function() {
    cout << "some output\n";
    cout << "this function does really heavy work\n";
    cout << "... and lots of it...\n";
}

int main() {
    cout << "Readable from normal stdout\n";

    {
        redirect_cout_region _ {"/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter7/data/output.txt"};
        // 把下面的 cout 的内容输出到了文件中去
        cout << "Only visible in output.txt\n";
        my_output_heavy_function();
        // 重定向缓冲区到另一个文件当中去了
        redirect_cout_region _2 {"/Users/momo/Desktop/CPP17_STL_COOKBOOK/Chapter7/data/fofo.txt"};
        cout << "fofo\n";
    }

    {   // 这一个部分，默认构造函数中 ofs 没有打开任何文件
        //我们重定向是输出是会被丢弃的不会被保存
        redirect_cout_region _;
        cout << "This output will completely vanish\n";
    }

    cout << "Readable from normal stdout again\n";

    return 0;
}
