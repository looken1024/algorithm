#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

template <typename T>
class QuickSort {
public:
    static void sort(std::vector<T>& s);

private:
    static void sort(std::vector<T>& s, int begin, int end);

};

#endif
