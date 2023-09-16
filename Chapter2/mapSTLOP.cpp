//
// Created by Momo on 2023/9/12.
//

#include "mapSTL操作.h"

void try_emplace_in_use() {
    std::map<int, std::string> myMap;

    /** map.try_emplace() 的返回值规则
     * 1. 一个 auto 变量接受的话，返回一个 pair<iterator, bool>
        * 1.1 插入成功 it 指向 key 的 键值对，bool 是 true
        * 1.2 插入失败 it 指向 key 的 键值对，bool 是 false
     * 2. 解包接受返回值，更加现代化 auto [it, success]
     * */
    // map.try_emplace() 插入键值对，如果键已存在，则不插入
    auto result1 = myMap.try_emplace(1, "One");
    auto result2 = myMap.try_emplace(2, "Two");
    auto result3 = myMap.try_emplace(1, "Another One"); // 这个键已经存在

    // 打印插入结果 (拆入成功就是 true，反之 false)
    std::cout << "Insertion result 1: " << result1.second << std::endl;
    std::cout << "Insertion result 2: " << result2.second << std::endl;
    std::cout << "Insertion result 3: " << result3.second << std::endl;

    // 虽然失败，但是我们看看 result 返回的迭代是谁
    cout << "it of result 3: " << result3.first->first
         << ": " << result3.second << endl;

    // 打印 map 的内容
    for (const auto &pair: myMap)
        std::cout << pair.first << ": "
                  << pair.second << std::endl;
}

void demo1() {
    for (const auto &b: billionaires) {
        auto [iter, success]
                = m.try_emplace(b.country, std::move(pair<billionaire, size_t>(b, 1)));

        if (!success) iter->second.second += 1;
    }
    // 第一次解包
    for (const auto &[key, value]: m) {
        // 这个是从 pair 里面解包（第二次解包）
        const auto &[b, count] = value;
        cout << b.country << " : " << count
             << " billionaires. Richest is "
             << b.name << " with " << b.dollars << " B$\n";
    }
}

void demo2() {
    std::map<std::string, size_t> m1 = {
            {"b", 1},
            {"c", 2},
            {"d", 3}
    };

    // 创建一个 map末尾 的迭代器
    auto insert_it(std::end(m1));

    for (const auto &s: {"z", "y", "x", "w"})
        // 在末尾位置插入新的值
        insert_it = m1.insert(insert_it, {s, 1});
    m1.insert({"a", 1});

    show_map(m1);
}

void mod_map() {
    map<int, string> race_placement{
            {1, "Mario"},
            {2, "Luigi"},
            {3, "Bowser"},
            {4, "Peach"},
            {5, "Yoshi"},
            {6, "Koopa"},
            {7, "Toad"},
            {8, "Donkey Kong Jr."}
    };
    show_map(race_placement);

    /** @brief 交换 map 的键
     * map 键是按序排列的，我们直接交换键，就相当于修改顺序了，这是不允许的
     * 所以我们采取提出，交换，再次插入的方案
     * */

    // map.extract() 从 map 中提取一个元素，返回包含改元素节点的指针
    auto a(race_placement.extract(3));
    auto b(race_placement.extract(8));

    show_map(race_placement);

    swap(a.key(), b.key());

    race_placement.insert(move(a));
    race_placement.insert(move(b));

    show_map(race_placement);

    // 如果 map.extract() 提取一个找不到的对象，会返回 none_type
    if (!race_placement.extract(123)) {
        cout << "NULL!!!\n";
    }
}

void demo3() {
    // 创建一个自定义类型的 unordered_map
    unordered_map<coord, int>{
            {{0,  1},  20},
            {{20, 10}, 30}
    };
}