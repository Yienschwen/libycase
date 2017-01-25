#ifndef LIBYCPP_SORT_H
#define LIBYCPP_SORT_H

#include <vector>

namespace ycpp {
    namespace sort{
        template <class T>
        std::vector<T> heapsort(std::vector<T>);

        template <class T>
        std::vector<T> quicksort(std::vector<T>);
    }
}
#endif