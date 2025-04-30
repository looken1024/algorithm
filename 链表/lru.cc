#include <lru.h>

template <typename K, typename V>
LRU<K, V>::LRU(const int max_size_, const K default_key_, const V default_value_) {
    max_size = max_size_;
    head = new LRUNode<K, V>(default_key_, default_value_);
    tail = new LRUNode<K, V>(default_key_, default_value_);
    head->next = tail;
    tail->pre = head;
    size = 0;
    default_key = default_key_;
    default_value = default_value_;
}

template <typename K, typename V>
void LRU<K, V>::put(K key, V value) {
	if (node_map.find(key) != node_map.end()) {
	    LRUNode<K, V>* t = node_map[key];
	    erase_node(t);
	    put_node_to_tail(t);
	    return;
	}
	LRUNode<K, V>* t = new LRUNode<K, V>(key, value);
	put_node_to_tail(t);
	node_map[key] = t;
	size++;
	if (size > max_size) {
	    node_map.erase(head->next->key);
	    erase_node(head->next);
	    size--;
	}
}

template <typename K, typename V>
V LRU<K, V>::get(K key) {
    if (node_map.find(key) == node_map.end()) {
	return default_value;
    }
    LRUNode<K, V>* node = node_map[key];
    erase_node(node);
    put_node_to_tail(node);
    return node->value;
}

template <typename K, typename V>
void LRU<K, V>::erase_node(LRUNode<K, V>* node) {
	node->pre->next = node->next;
	node->next->pre = node->pre;
}

template <typename K, typename V>
void LRU<K, V>::put_node_to_tail(LRUNode<K, V>* node) {
	node->pre = tail->pre;
	node->next = tail;
	tail->pre->next = node;
	tail->pre = node;
}

// 模板代码可见性
template class LRUNode<int, int>;
template class LRU<int, int>;


