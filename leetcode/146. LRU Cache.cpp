/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    LRU Cache
 Source:     https://leetcode.com/problems/lru-cache/?tab=Description
 Tags:       {Design}
 Company:    Google, Uber, Facebook, Twitter, Zenefits, Amazon, Microsoft, Snapchat, 
             Yahoo, Bloomberg, Palantir 

 Notes:
 Design and implement a data structure for Least Recently Used (LRU) cache. 
 It should support the following operations: get and put.

 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

 Follow up:
 Could you do both operations in O(1) time complexity?

 Example:

 LRUCache cache = new LRUCache( 2  capacity  );

 cache.put(1, 1);
 cache.put(2, 2);
 cache.get(1);       // returns 1
 cache.put(3, 3);    // evicts key 2
 cache.get(2);       // returns -1 (not found)
 cache.put(4, 4);    // evicts key 1
 cache.get(1);       // returns -1 (not found)
 cache.get(3);       // returns 3
 cache.get(4);       // returns 4

 Solution: Hashmap + linkedlist.
           Refer linkedlist: http://www.cplusplus.com/reference/list/list/ 
*/

class LRUCache{
public:
    LRUCache(int capacity) : size(capacity) {}
    int get(int key) {
        if (cachemap.count(key)) {
            auto it = cachemap[key];
            int val = cachemap[key]->value;
            cachelist.erase(it);
            cachelist.push_front(CacheNode(key, val));
            cachemap[key] = cachelist.begin();
            return val;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if (cachemap.count(key)) {
            auto it = cachemap[key];
            cachelist.erase(it);
            cachelist.push_front(CacheNode(key, value));
            cachemap[key] = cachelist.begin();
        } else {
            if (size == cachelist.size()) {
                cachemap.erase(cachelist.back().key); // delete last one
                cachelist.pop_back();
            }
            cachelist.push_front(CacheNode(key, value));
            cachemap[key] = cachelist.begin();
        }
    }
    
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k, int v) : key(k), value(v) {}
    };

    list<CacheNode> cachelist;
    unordered_map<int, list<CacheNode>::iterator> cachemap; // 
    int size;
};


class LRUCache{
public:
	LRUCache(int capacity) {
		size = capacity;    
	}

	int get(int key) {
		if(!kmap.count(key)) return -1;
		cachelist.splice(cachelist.begin(), cachelist, kmap[key]);
		return kmap[key]->value;
	}

	void set(int key, int value) {
		if(kmap.count(key)){
			cachelist.splice(cachelist.begin(), cachelist, kmap[key]);
			kmap[key]->value = value;
		} else {
			if(cachelist.size() == size){
				kmap.erase(cachelist.back().key);
				cachelist.pop_back();
			}
			cachelist.push_front(data(key, value));
			kmap[key] = cachelist.begin();
		}
	}
private:
	struct data{
		int key;
		int value;
		data(int k, int v) : key(k), value(v) {}
	};

	int size;
	list<data> cachelist;
	unordered_map<int, list<data>::iterator> kmap;
};