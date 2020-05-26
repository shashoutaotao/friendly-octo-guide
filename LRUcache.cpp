struct block {
    int key;
    int value;
    bool isUsing = false;
    int timestamp;
};

int TIMESTAMP = 0;

class LRUCache {
private:
    vector<block> cache;
    int size;
public:
    LRUCache(int capacity) {
        cache.resize(capacity);
        size = 0;
    }
    
    // Get the value (will always be positive) of the key
    // if the key exists in the cache, otherwise return -1.
    int get(int key) {
        for(int i = 0; i < cache.size(); ++i) {
            if(cache[i].isUsing && key == cache[i].key) {
                ++TIMESTAMP;
                cache[i].timestamp = TIMESTAMP;
                return cache[i].value;
            }
        }
        return -1;
    }
    // Set or insert the value if the key is not already present.
    // When the cache reached its capacity, it should invalidate
    // the least recently used item before inserting a new item.
    void put(int key, int value) {
        // check if present
        for(int i = 0; i < cache.size(); ++i) {
            if(cache[i].isUsing && key == cache[i].key) {
                ++TIMESTAMP;
                cache[i].value = value;
                cache[i].timestamp = TIMESTAMP;
                return;
            }
        }
        ++TIMESTAMP;
        if(size == cache.size()) {
            // full cache, evict the LRU
            int leastLRU = 0;
            for(int i = 1; i < cache.size(); ++i) {
                if(cache[leastLRU].timestamp > cache[i].timestamp) {
                    leastLRU = i;
                }
            }
            cache[leastLRU].timestamp = TIMESTAMP;
            cache[leastLRU].key = key;
            cache[leastLRU].value = value;
        }
        else {
            // has empty slot
            for(int i = 0; i < cache.size(); ++i) {
                if(!cache[i].isUsing) {
                    cache[i].isUsing = true;
                    cache[i].timestamp = TIMESTAMP;
                    cache[i].key = key;
                    cache[i].value = value;
                    ++size;
                    break;
                }
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
