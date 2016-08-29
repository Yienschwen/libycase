// #include <iostream>
#include <vector>

#include "Quicksort.hpp"

int main() {
    int a[] = {1, 3, 7, 6, 5, 2, 8, 4};
    std::vector<int> v1(a, a + 8);
    std::vector<int> v2 = Quicksort(v1);
    std::size_t count = 0;
    if (v2.size() != v1.size())
        return -1;
    else {
        for (std::vector<int>::iterator it = ++(v2.begin()); it != v2.end(); ++it) {
        if (*it < *(it - 1)) 
            count++;
        }
        return count;
    }
}