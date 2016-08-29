#include <iostream>
#include <vector>

#include "Heapsort.hpp"

int main() {
    int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    std::vector<int> v1(a, a + 10);
    std::vector<int> v2 = Heapsort(v1);
    std::size_t count = 0;
    for (std::vector<int>::iterator it = ++(v2.begin()); it != v2.end(); ++it) {
        if (*it < *(it - 1)) 
            count++;
    }
    return count;
}