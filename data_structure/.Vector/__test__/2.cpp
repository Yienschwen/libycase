#include <iostream>

#include "Vector.cpp"

int main() {
    Vector<int> v1;
    std::cout << "Length of v1: " << v1.length() << '\n';
    for (int i = 0; i < 10; i++) {
        v1.append(i);
    }
    std::cout << "Length after append: " << v1.length() << '\n';
    std::cout << "Traversal:" << '\n';
    unsigned count = 0;
    for (int i = 0; i < v1.length(); i++) {
        std::cout << v1[i] << '\n';
        if (v1[i] != i)
            count++;
    }
    return count;
}