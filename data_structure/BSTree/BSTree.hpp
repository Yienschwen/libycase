#ifndef LIBYCPP_BSTREE_H_
#define LIBYCPP_BSTREE_H_

#include <vector>

template <class T>
class BSTree {
    // how to implement node? => TCP3L
public:
    // insert
    bool exist(const T& varInput) {}

    std::vector<T> inorder() {}

    T min() {}
    T max() {}

    // sucessor

    void insert(const T& varInput) {}
    bool remove(const T& varInput) {} // what type to return?

    //TODO: iterator

    
private:
    // delete
    // transplant

};

#endif