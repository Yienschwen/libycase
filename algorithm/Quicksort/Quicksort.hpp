#ifndef LIBYCPP_QUICKSORT_H_
#define LIBYCPP_QUICKSORT_H_

#include <vector>
#include <utility>

template <class T>
std::size_t Quicksort_partition(std::vector<T>& vctInput, std::size_t p, std::size_t r) {
    T x = vctInput[r];
    std::size_t i = p - 1;
    for (std::size_t j = p; j <= r - 1; j++) {
        if (vctInput[j] <= x) {
            i++;
            std::swap(vctInput[i], vctInput[j]);
        }
    }
    std::swap(vctInput[i + 1], vctInput[r]);
    return (i + 1);
}

template <class T>
void Quicksort(std::vector<T>& vctInput, std::size_t p, std::size_t r) {
    if (p < r) {
        std::size_t q = Quicksort_partition(vctInput, p, r);
        if (q > 0)
            Quicksort(vctInput, p, q - 1);
        if (q < vctInput.size() - 1)
            Quicksort(vctInput, q + 1, r);
    }
}

template <class T>
std::vector<T> Quicksort(std::vector<T> vctInput) {
    Quicksort(vctInput, 0, vctInput.size() - 1);
    return vctInput;
}

#endif