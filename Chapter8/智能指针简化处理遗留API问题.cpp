//
// Created by Momo on 2023/10/29.
//

#include "智能指针简化处理遗留API问题.h"

int main() {
    auto ps =
            make_shared_foo("shared Foo instance");
    auto pu =
            make_unique_foo("unique Foo instance");
    return 0;
}