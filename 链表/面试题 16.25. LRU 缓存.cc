/*
设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。
它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

示例：
LRUCache cache = new LRUCache(2);
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        _head = new LRUNode(-1, -1);
        _tail = new LRUNode(-1, -1);
        _head->_next = _tail;
        _tail->_pre = _head;
    }

    struct LRUNode {
        LRUNode(int key, int val) {
            _key = key;
            _val = val;
            _next = NULL;
            _pre = NULL;
        }
        int _val;
        int _key;
        LRUNode* _next;
        LRUNode* _pre;
    };
    
    int get(int key) {
        if (_map.find(key) == _map.end()) {
            return -1;
        }
        LRUNode* tmp = _map[key];
        erase_node(tmp);
        put_to_tail(tmp);
        return tmp->_val;
    }

    void erase_node(LRUNode* tmp) {
        _map.erase(tmp->_key);
        tmp->_pre->_next = tmp->_next;
        tmp->_next->_pre = tmp->_pre;
        _size--;
    }

    void put_to_tail(LRUNode* tmp) {
        tmp->_pre = _tail->_pre;
        _tail->_pre->_next = tmp;
        _tail->_pre = tmp;
        tmp->_next = _tail;
        _map[tmp->_key] = tmp;
        _size++;
    }
    
    void put(int key, int value) {
        LRUNode* tmp;
        if (_map.find(key) == _map.end()) {
            tmp = new LRUNode(key, value);
        } else {
            tmp = _map[key];
            tmp->_val = value;
            erase_node(tmp);
        }
        put_to_tail(tmp);
        if (_size > _capacity) {
            erase_node(_head->_next);
        }
    }

private:
    int _capacity;
    int _size;
    LRUNode* _head;
    LRUNode* _tail;
    map<int, LRUNode*> _map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
