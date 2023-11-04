//
// Created by Momo on 2023/10/27.
//

#include "处理共享堆内存.h"

static void demo1() {
    shared_ptr<Foo> fa;
    {   cout << "Inner scope begin\n";
        // 共享指针的创建
        shared_ptr<Foo> f1{new Foo{"foo"}};     // 显式
        auto f2(make_shared<Foo>("bar"));   // 隐式

        cout << "f1's use counter at " << f1.use_count() << '\n';
        fa = f1;    // 创建指针的共享
        cout << "f1's use counter at " << f1.use_count() << '\n';
    }
    // 离开代码块的时候，就会释放共享对象
    cout << "Back to outer scope\n";
    // shared_pointer.count()：显示共享对象的数量
    cout << fa.use_count() << '\n';

    // 这里你会看到，我们拷贝了一个指针变量，所以个数位 2
    cout << "first f() call\n";
    f(fa);

    // 这里是 move，不是拷贝了一个新的，所以共享个数是 1
    cout << "second f() call\n";
    f(move(fa));

    cout << "end of main()\n";
}


int main() {
    demo1();

    return 0;
}