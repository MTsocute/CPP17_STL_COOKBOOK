//
// Created by Momo on 2023/9/15.
//

#ifndef STL_PRIORITY_QUEUE_H
#define STL_PRIORITY_QUEUE_H

#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

using item_type = std::pair<int, std::string>;

void p_queue_in_use();

void demo1();

void p_queue_in_use() {
    std::priority_queue<item_type> q;

    initializer_list<item_type> il = {
            {1, "dishes"},
            {0, "watch tv"},
            {2, "do homework"},
            {0, "read comics"},
    };

    /**
     * @brief priority_queue 的排序规则
        * 按照内部规则排序，而非进入的顺序
        * 如果有类似于 pair 这种多类型数据，就顺位比较
     * */
    for (const auto &p: il)
        q.push(p);

    // priority_queue push 元素会按照某种规则排序的元素的
    while (!q.empty()) {
        // priority_queue.top() 返回队列首元素
        cout << q.top().first
             << ": " << q.top().second << '\n';
        q.pop();    // priority_queue.pop() 删除首元素
    }
    std::cout << '\n';
}

#endif //STL_PRIORITY_QUEUE_H
