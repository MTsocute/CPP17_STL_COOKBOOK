#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

void print(const vector<int> &v) {
    copy(begin(v), end(v), ostream_iterator<int>
            {cout, ", "});
    cout << '\n';
}

auto odd_number([](int i) {
    return i % 2 != 0;
});
auto even_number([](int i) {
    return i % 2 == 0;
});


template<typename T>
void replace_in_use(vector<T> &&v) {
    // replace(): 替换一定范围的所有数据为制定的数据
    replace(begin(v), end(v), 4, 123);
    print(v);
}


template<typename T>
void remove_cp_if_in_use(vector<T> &&v) {
    vector<int> v2;
    vector<int> v3;

    // remove_copy_if(): 当不满足谓词条件时，会从源容器中拷贝到另一个容器中
    remove_copy_if(begin(v), end(v),
                   back_inserter(v2), odd_number);
    // copy_if(): 只会拷贝满足的条件的元素，到另一个容器中
    copy_if(begin(v), end(v),
            back_inserter(v3), even_number);

    ::print(v2);
    ::print(v3);

    ::print(v);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//    replace_in_use(std::move(v));

    remove_cp_if_in_use(std::move(v));

    return 0;
}