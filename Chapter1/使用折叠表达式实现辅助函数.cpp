//
// Created by Momo on 2023/9/9.
//

#include <iomanip>
#include <iostream>

using namespace std;

template<class ... T>
inline static auto cat_string(T ... args) -> common_type_t<T ...> {
    return ((args) + ...);
}

template<typename ... Ts>
inline static auto product(Ts ... ts) {
    return (ts * ... * 1);
}

template<typename R, typename ... Ts>
auto matches(const R &range, Ts ... ts) {
    // 平时的 ts + ... 就是我们参数包的和
    // 但是如果，我们有一个容器，一个参数包，我们就有很多的选择
    // 这里是把参数用STL找在容器中出现了多少次，各个元素出现的次数返回一个和
    return (std::count(std::begin(range),
                       std::end(range), ts) + ...);
}

// 利用多模板参数检测所有参数是否都在某个范围
template<class U, class ...T>
bool all_in_range(U min, U max, T ... args) {
    return ((min <= args and args <= max) && ...);
}

// 利用多模板参数给容器塞入新的数据
template <typename T, typename ... Ts>
void insert_all(std::vector<T> &vec, Ts ... ts){
    (vec.push_back(ts), ...);
}


int main() {
    auto tmp = make_tuple("123", 13, 14, "momo", "fuck", "momo");

    cout << "bool = " <<
         all_in_range(120, 500, 244, 8000, 123) << endl;

    return 0;
}