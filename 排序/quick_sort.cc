#include <quick_sort.h>

#include <cstdint>

template <typename T>
void QuickSort<T>::sort(std::vector<T>& s)
{
    sort(s, 0, s.size() - 1);
}

template <typename T>
void QuickSort<T>::sort(std::vector<T>& s, int begin, int end)
{
    int l = begin, r = end;
    if (begin >= end) {
        return;
    }
    T tmp = s[begin];
    while (begin < end) {
        while (begin < end && s[end] >= tmp) {
            end--;
        }
        s[begin] = s[end];
        while (begin < end && s[begin] <= tmp) {
            begin++;
        }
        s[end] = s[begin];
    }
    s[begin] = tmp;
    sort(s, l, begin - 1);
    sort(s, begin + 1, r);
}

// 模板代码可见性
template class QuickSort<int32_t>;
template class QuickSort<int64_t>;
template class QuickSort<double>;
template class QuickSort<char>;

