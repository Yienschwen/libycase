#include <cstring> // memcpy

#include "Vector.hpp"

template <class T>
Vector<T>::Vector() {
    ptrPool = 0;
    usgCount = 0;
    usgCapacity = 0;
}

template <class T>
Vector<T>::~Vector() {
    if (usgCount != 0) {
        delete [] ptrPool;
    }
}

template <class T>
unsigned Vector<T>::length() {
    return usgCount;
}

// TODO: deal with bad_alloc()
template <class T>
void Vector<T>::append(T varInput) {
    if (usgCount == usgCapacity) {
        T* ptrTemp = new T [usgCapacity];
        memcpy(ptrTemp, ptrPool, usgCapacity * sizeof(T));
        delete [] ptrPool;
        ptrPool = new T [usgCapacity * 2 + 1];
        memcpy(ptrPool, ptrTemp, usgCapacity * sizeof(T));
        delete [] ptrTemp;
        usgCapacity = usgCapacity * 2 + 1;
    }
    ptrPool[usgCount] = varInput;
    usgCount++;
}

