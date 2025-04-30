#include <string>
#include <iostream>

#include <lru.h>

int main() {
    LRU<int, int> lru(3, -1, -1);
    for (int i = 0; i < 10; i++) {
	lru.put(i, i + 1);
    }

    for (int i = 0; i < 10; i++) {
	std::cout << lru.get(i) << std::endl;
    }

    return 0;
}
