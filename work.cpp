#include <algorithm>
#include <iostream>

template<class T>
void show_type(T) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

int main() {
    // どのオーバーロードを取るか明示的にキャスト
    const int& (*p)(const int&, const int&) = std::max<int>;
    show_type(p);
}
