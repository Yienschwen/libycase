#include <iostream>

#include "BSTree.hpp"

int main() {
    BSTree<int> bstMain;
    int a[] = {6, 5, 7, 2, 5, 8};
    std::vector<int> vctPool(a, a + 6);
    for (std::vector<int>::iterator it = vctPool.begin(); it != vctPool.end(); ++it) {
        bstMain.insert(*it);
    }
    BSTree<int> bstCopy = BSTree<int>(bstMain);
    bstMain.clear();
    std::cout << "Count: " << bstCopy.size() << '\n';
    std::cout << "Inorder: ";
    std::vector<int> vctInorder = bstCopy.inorder();
    for (std::vector<int>::iterator it = vctInorder.begin(); it != vctInorder.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    std::cout << "Max: " << bstCopy.max() << '\n';
    std::cout << "Min: " << bstCopy.min() << '\n';
    bstCopy.clear();
    std::cout << "Count after clear: " << bstCopy.size() << '\n';
    return 0;
}
