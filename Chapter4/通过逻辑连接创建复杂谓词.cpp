//
// Created by Momo on 2023/9/22.
//

#include "通过逻辑连接创建复杂谓词.h"

// 使用 combine 构建一个新的谓词函数，检查字符串同时以 'a' 开头并以 'b' 结尾
auto starts_with_a_and_ends_with_b =
    combine(std::logical_and<bool>{}, begins_with_a, ends_with_b);

int main() {
    return 0;
}