//
// Created by Momo on 2023/10/24.
//

#include "存储不同类型.h"

static void demo1() {
    animal myAnimal = cat("Whiskers");

    if (is_type<cat>(myAnimal)) {
        std::cout << "It's a cat!" << std::endl;
        std::get<cat>(myAnimal).meow();
    } else if (is_type<dog>(myAnimal)) {
        std::cout << "It's a dog!" << std::endl;
        std::get<dog>(myAnimal).woof();
    } else
        std::cout << "It's neither a cat nor a dog." << std::endl;
}

/* 两种不同从混杂类型中筛选具体类型的方法 */
static void demo2() {
    // 根据 variant 创建存储多类型的数据结构
    list<animal> l = {cat{"Tuba"}, dog{"Balou"}, cat{"Bobby"}};
    for (const animal &a: l) {
        // variant.index(): 根据其创建存储类型的顺序对应index决定变量类型
        switch (a.index()) {
            case 0:
                // get<type>(variant)：获取 variant 的一个type的对象
                get<dog>(a).woof();
                break;
            case 1:
                get<cat>(a).meow();
                break;
        }
    }
    cout << "-----" << endl;
}

static void demo3() {
    list<animal> l = {cat{"Tuba"}, dog{"Balou"}, cat{"Bobby"}};
    for (const animal &a: l) {
        // get_if<type>(variant): 如果当前类型和 type 相同返回对象的指针，反之 null
        if (const auto d = get_if<dog>(&a); d)
            d->woof();
        else if (const auto c = get_if<cat>(&a); c)
            c->meow();
    }
    cout << "-----\n";
}

static void demo4() {
    list<animal> l = {cat{"Tuba"}, dog{"Balou"}, cat{"Bobby"}};

    cout << fmt::format("There are {} cats and {} dogs in the list.\n",
                        count_if(begin(l), end(l), is_type<cat>),
                        count_if(begin(l), end(l), is_type<dog>));
}

static void demo5() {
    cat demo{"babe"};
//    animal_voice{}(demo);

    // 使用 variant 创建变量
    animal demo2 = cat("momo");

    // visit()：自动使用 variant 对应类型的 operator() 运算符
    std::visit(animal_voice{}, demo2);
}


int main() {
//    demo1();
//    demo2();
//    demo3();
//    demo4()
//    demo5();
    return 0;
}