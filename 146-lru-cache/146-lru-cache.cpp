class LRUCache {
    list<int> lru;
    unordered_map<int, list<int>::iterator> cache;
    unordered_map<int, int> keyVal;
    int capacity = 0;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            changeToMRU(key);
            return keyVal[key];
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())      
            changeToMRU(key);
        
        else if(cache.size() < capacity){
            lru.push_front(key);
            cache[key] = lru.begin();
        }
        else if(cache.size() >= capacity){
            //evict
            int delKey = lru.back();
            cache.erase(delKey);    //remove from cache
            keyVal.erase(delKey);   //remove from keyVal
            lru.pop_back();
            //////
            lru.push_front(key);
            cache[key] = lru.begin();
        }
        keyVal[key] = value;
    }
    void changeToMRU(int key){
        lru.erase(cache[key]);
        lru.push_front(key);
        cache[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */