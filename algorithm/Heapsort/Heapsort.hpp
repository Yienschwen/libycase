#ifndef LIBYCPP_HEAPSORT_H
#define LIBYCPP_HEAPSORT_H

#include <vector>
#include <cstddef>
#include <utility>

inline std::size_t Heap_Parent(std::size_t idx) { return ((idx - 1) / 2); }

std::size_t Heap_Left(std::size_t idx) { return (2 * idx + 1); }

std::size_t Heap_Right(std::size_t idx) { return (2 * (idx + 1)); }

template <class T>
void Max_Heapify(std::vector<T>& vctInput, std::size_t idx) {
    std::size_t sztLeft = Heap_Left(idx);
    std::size_t sztRight = Heap_Right(idx);
    std::size_t sztLargest;
    if ((sztLeft < vctInput.size()) && (vctInput[sztLeft] > vctInput[idx])) {
        sztLargest = sztLeft;
    }
    else {
        sztLargest = idx;
    }
    if ((sztRight < vctInput.size()) && (vctInput[sztRight] > vctInput[sztLargest])) {
        sztLargest = sztRight;
    }
    if (idx != sztLargest) {
        std::swap(vctInput[idx], vctInput[sztLargest]);
        Max_Heapify(vctInput, sztLargest);
    }
    
}

template <class T>
void Build_Max_Heap(std::vector<T>& vctInput) {
     //???
    if (vctInput.size() != 1) {
        std::size_t idx = Heap_Parent(vctInput.size() - 1);
        if (idx != 0) {
            do {
                Max_Heapify(vctInput, idx);
                idx--;
            } while (idx != 0);
        }
    }
}

template <class T>
std::vector<T> Heapsort(std::vector<T> vctInput) {
    Build_Max_Heap(vctInput);
    std::vector<T> vctReturn;
    for (std::size_t i = vctInput.size() - 1; i >= 1; i--) {
        std::swap(vctInput[0], vctInput[i]);
        vctReturn.insert(vctReturn.begin(), vctInput[i]);
        vctInput.pop_back();
        Max_Heapify(vctInput, 0);
    }
    if (vctInput.size() != 0) {
        vctReturn.insert(vctReturn.begin(), vctInput[0]);
    }
    return vctReturn;
}

#endif