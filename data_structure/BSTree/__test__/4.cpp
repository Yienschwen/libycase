#include <iostream>

#include "BSTree.hpp"

/*
 *  test case for BSTree:
 *      exist
 */

int main() {
    BSTree<int> bstMain;
    int a[] = {6, 5, 7, 2, 5, 8};
    std::vector<int> vctPool(a, a + 6);
    for (std::vector<int>::iterator it = vctPool.begin(); it != vctPool.end(); ++it) {
        bstMain.insert(*it);
    }
    int intReturn = 0;
    bool boolExist2 = bstMain.exist(2);
    std::cout << "bstMain.exist(2) = " << boolExist2 << '\n';
    if (!boolExist2)
        intReturn++;
    bool boolExist9 = bstMain.exist(9);
    std::cout << "bstMain.exist(9) = " << boolExist9 << '\n';
    if (boolExist9)
        intReturn++;
    bool boolRemove = bstMain.remove(6);
    if (!boolRemove)
        intReturn++;
    bool boolExist6 = bstMain.exist(6);
    if (boolExist6)
        intReturn++;
    std::cout << "Inorder: ";
    std::vector<int> vctInorder = bstMain.inorder();
    for (std::vector<int>::iterator it = vctInorder.begin(); it != vctInorder.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    return intReturn;
}
