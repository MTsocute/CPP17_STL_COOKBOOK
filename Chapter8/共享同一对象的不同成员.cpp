//
// Created by Momo on 2023/10/30.
//

#include "共享同一对象的不同成员.h"

int main() {
    /* 指向 Person 实例中的指定变量 */
    shared_ptr<string> shared_name;
    shared_ptr<size_t> shared_age;

    {   // 共享指针的指向一个共享指针的成员变量操作
        auto sperson = make_shared<person>("momo", 123);
        shared_name = shared_ptr<string>(sperson, &sperson->name);
        // 第二个参数是要获取地址
        shared_age = shared_ptr<size_t>(sperson, &((*sperson).age));

        cout << "count: " << sperson.use_count() << endl;
    }

    // 离开之后，仍然存在
    cout << "name: " << *shared_name
         << "\nage: " << *shared_age
         << "\ncount: " << shared_name.use_count()
         << '\n';

    return 0;
}