#ifndef LIBYCPP_DS_DISJOINT_H
#define LIBYCPP_DS_DISJOINT_H

#include <vector>
#include <cstddef>
#include <stdexcept>

namespace ycpp {
template <class T>
    class disjoint {
        public:
            void make_set(const T& varInput) {
                this->val.push_back(varInput);
                this->rank.push_back(0);
                std::size_t sztLast = parent.size();
                this->parent.push_back(sztLast);
            }

            void merge_val(const T& x, const T& y) {
                this->link(this->find_set(x), this->find_set(y));
            }

            void merge_set(const std::size_t& x, const std::size_t& y) {
                this->link(this->find_index(x), this->find_inde(y));
            }

            std::size_t find_set(const T& varInput) {
                for (std::size_t i = 0; i < this->val.size(); i++) {
                    if (this->val[i] == varInput)
                        return this->find_index(i);
                }
                throw std::runtime_error("Required value not found.");
            }

        private:
            std::size_t find_index(std::size_t i) {
                if (this->parent[i] != i) {
                    this->parent[i] = this->find_index(this->parent[i]);
                }
                return this->parent[i];
            }

            void link(std::size_t x, std::size_t y) {
                if (this->rank[x] > this->rank[y]) {
                    this->parent[y] = x;
                }
                else {
                    this->parent[x] = y;
                    if (this->rank[x] == this->rank[y]) {
                        this->rank[y] += 1;
                    }
                }
            }

            std::vector<std::size_t> parent;
            std::vector<T> val;
            std::vector<unsigned> rank;
    };
}
#endif