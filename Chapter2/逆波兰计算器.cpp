//
// Created by Momo on 2023/9/15.
//
#include "逆波兰计算器.h"


int main() {
    stringstream s{"3 2 1 + * 2 /"};
    try {
        // 默认情况下，istream_it 会使用 space 作为分隔符
        cout << evaluate_rpn(istream_iterator<string>{s}, {}) << '\n';
    } catch (const invalid_argument &e) {
        cout << "Invalid operator: " << e.what() << '\n';
    }
    return 0;
}