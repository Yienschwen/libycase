#ifndef LIBYCPP_HEAPSORT_H
#define LIBYCPP_HEAPSORT_H

#include <vector>
#include <cstddef>
#include <utility>
#include <cassert>
#include <functional>

template <class T>
class Heapsort {
public:
    static void sort(std::vector<T>& vctRef, std::function<bool(T, T)> cmp=std::less<T>()) {
        Heapsort hpsort = Heapsort(vctRef, cmp);
        hpsort._SortInplace();
    }

private:
    Heapsort() {}   // private default constructor
    ~Heapsort() {}  // private default destructor

    std::vector<T>& vctInput;
    std::size_t sztHeapSize;
    std::function<bool(T,T)> funcCmp;

    // using member initializer to make compiler happy
    // or it'll complain about reference initialization of this->vctInput
    Heapsort(std::vector<T>& vctRef, std::function<bool(T,T)> cmp): 
        vctInput(vctRef), sztHeapSize(vctRef.size()), funcCmp(cmp) {} 

    void _SortInplace() {
        _BuildHeap();
        for (std::size_t i = vctInput.size() - 1; i >= 1; i--) {
            std::swap(vctInput[0], vctInput[i]);
            sztHeapSize -= 1;
            _Heapify(0);
        }
    }

    void _BuildHeap() {
        if (vctInput.size() != 1) {
            std::size_t idx = _Parent(vctInput.size() - 1);
            for (;;) {
                _Heapify(idx);
                // this ugly branch should be avoided
                // but what I want to avoid more is 
                // unnecessary increment(decrement) on std::size_t
                // which is UNSIGNED
                if (idx != 0) {
                    idx--;
                }
                else {
                    break;
                }
            }
        }
    }

    void _Heapify(std::size_t idx) {
        auto sztLeft = _Left(idx);
        auto sztRight = _Right(idx);
        std::size_t sztToSwap;
        if ((sztLeft < sztHeapSize) && funcCmp(vctInput[idx], vctInput[sztLeft])) {
            sztToSwap = sztLeft;
        }
        else {
            sztToSwap = idx;
        }
        if ((sztRight < sztHeapSize) && funcCmp(vctInput[sztToSwap], vctInput[sztRight])) {
            sztToSwap = sztRight;
        }
        if (idx != sztToSwap) {
            std::swap(vctInput[idx], vctInput[sztToSwap]);
            _Heapify(sztToSwap);
        }
    }

    inline std::size_t _Parent(std::size_t idx) {
        assert(idx > 0); // prevent overflow
        return ((idx - 1) / 2);
    }

    inline std::size_t _Left(std::size_t idx) {
        return (2 * idx + 1);
    }

    inline std::size_t _Right(std::size_t idx) {
        return (2 * (idx + 1));
    }
};

#endif