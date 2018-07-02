#include <iostream>
#include <vector>

#include "../Heapsort.hpp"

int main() {
    // int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    // std::vector<int> v1({16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    std::vector<int> v2({4, 14, 16, 7, 9, 3, 2, 8, 1});
    // std::vector<int> v2({ 2, 0});
    // std::vector<int> v2 = v1;
    Heapsort<int>::sort(v2, std::less<int>());
    std::size_t count = 0;
    for (std::vector<int>::iterator it = ++(v2.begin()); it != v2.end(); ++it) {
        if (*it < *(it - 1)) 
            count++;
    }

    // for (auto i : v1) {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';

    for (auto i : v2) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return count;
}