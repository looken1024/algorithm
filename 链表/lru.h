#ifndef LRU_h
#define LRU_H

#include <map>

template <typename K, typename V>
struct LRUNode {
    LRUNode(const K key_, const V value_) {
	key = key_;
	value = value_;
	next = NULL;
	pre = NULL;
    }

    K key;
    V value;
    LRUNode* next;
    LRUNode* pre;
};

template <typename K, typename V>
class LRU {
public:
    LRU(const int max_size_, K default_key_, V default_value_);

    void put(K key, V value);

    V get(K key);

private:
    void erase_node(LRUNode<K, V>* node);

    void put_node_to_tail(LRUNode<K, V>* node);

private:
    LRUNode<K, V>* head;
    LRUNode<K, V>* tail;
    std::map<K, LRUNode<K, V>*> node_map;
    int max_size;
    int size;
    K default_key;
    V default_value;
};

#endif
