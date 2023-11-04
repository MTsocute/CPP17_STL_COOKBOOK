//
// Created by Momo on 2023/10/24.
//
#include <fmt/core.h>
#include <iostream>
#include <iterator>
#include <list>
#include <any>
#include <map>

using namespace std;
using int_list = initializer_list<int>;


/* void* 的使用 */
static void unknown_type() {
    int x1 = 10;
    // void * 保存任意类型变量的地址
    void *genericPointer;

    // 我们可以用它来存储任意类型的变量
    genericPointer = &x1;
    // 通过强制类型转换，我们可以获取具体数据
    int value = *(static_cast<int *>(genericPointer));

    cout << "Value: " << value << endl;
}

/* 使用更加安全的 std::any */
void print_anything(const any &a) {
    // std::any.has_value(): 确定 any 变量中是否含有任何的值
    if (!a.has_value())
        cout << "None\n";
        /* 当不为空的时候，匹配找到起对应的类型 */
        // std::any.type(): 检查变量对应的类型
    else if (a.type() == typeid(string)) {
        // std::any_cast<type>(var): 转变 any 对象为对应的类型
        cout << fmt::format("It is string: \"{}\"\n",
                            any_cast<const string &>(a)) << endl;
    } else if (a.type() == typeid(int)) {
        cout << fmt::format("It is int: \"{}\"\n",
                            any_cast<int>(a)) << endl;
    } // 甚至可以存储复杂的数据结构
    else if (a.type() == typeid(int_list)) {
        const auto &l(any_cast<const int_list &>(a));
        cout << "It's a list: ";
        copy(begin(l), end(l),
             ostream_iterator<int>{cout, ", "});
        cout << '\n';
    }
    else if (a.type() == typeid(map<string, int>)) {
        cout << "It's a map: \n";
        for (const auto &[key, value] :any_cast<map<string, int>>(a))
            cout << fmt::format("{} - {}\n", key, value);
    }
    else cout << "Can't handle this item.\n";
}



int main() {
//    unknown_type();
//    print_anything({});
//    print_anything("abc"s);
//    print_anything(123);
//    print_anything(int_list{1, 2, 3});

    // 使用 in_place_type_t<>{}: 传递参数给 any 对象，减少不必要的拷贝浪费
//    print_anything(any(in_place_type_t<int_list>{}, {1,2,3}));

    map<string, int> m = {
            {"momo", 123},
            {"diedie", 444}
    };

    // std::ref
    print_anything(m);

    return 0;
}