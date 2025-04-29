#include <iostream>
#include <vector>
#include <algorithm>

#include <quick_sort.h>

int main() {

    std::vector<int32_t> s({4, 5, 6, 7, 8, 3, 2, 1, 4, 5, 6, 0, 1, 2, 23});
    QuickSort<int32_t>::sort(s);
    for (auto it : s) {
        std::cout << it << " " << std::endl;
    }
    std::cout << std::endl;

    std::vector<long> s2({4, 5, 6, 7, 8, 3, 2, 1, 4, 5, 6, 0, 1, 2, 23});
    QuickSort<long>::sort(s2);
    for (auto it : s2) {
        std::cout << it << " " << std::endl;
    }
    std::cout << std::endl;

    std::vector<char> s3({4, 5, 6, 7, 8, 3, 2, 1, 4, 5, 6, 0, 1, 2, 23});
    QuickSort<char>::sort(s3);
    for (auto it : s3) {
        std::cout << it << " " << std::endl;
    }
    std::cout << std::endl;

    std::vector<int32_t> s4({4, 5, 6, 7, 8, 3, 2, 1, 4, 5, 6, 0, 1, 2, 23});
    sort(s4.begin(), s4.end());
    for (auto it : s4) {
        std::cout << it << " " << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
