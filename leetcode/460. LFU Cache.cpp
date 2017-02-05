/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    LFU Cache
 Source:     https://leetcode.com/problems/lfu-cache/
 Difficulty: Hard
 Company:    Google

 Notes:
 Design and implement a data structure for Least Frequently Used (LFU) cache. 
 It should support the following operations: get and put.

 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 put(key, value) - Set or insert the value if the key is not already present. 
 When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. 
 For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), 
 the least recently used key would be evicted.

 Follow up:
 Could you do both operations in O(1) time complexity?

 Example:

 LFUCache cache = new LFUCache( 2 // capacity  );

 cache.put(1, 1);
 cache.put(2, 2);
 cache.get(1);       // returns 1
 cache.put(3, 3);    // evicts key 2
 cache.get(2);       // returns -1 (not found)
 cache.get(3);       // returns 3.
 cache.put(4, 4);    // evicts key 1.
 cache.get(1);       // returns -1 (not found)
 cache.get(3);       // returns 3
 cache.get(4);       // returns 4
*/

class LFUCache {
public:
    LFUCache(int capacity) {
        d_capacity = capacity;
    }
    
    int get(int key, int val = 0) {
        if (!keyMap.count(key)) {
            return -1;
        }
        int freq = keyMap[key]->freq + 1;
        val = val == 0 ? keyMap[key]->val : val;

        list<Data>::iterator iter;
        if (freqMap.count(freq)) {
            iter = d_list.insert(freqMap[freq], Data(key, val, freq));
        } else {
            iter = d_list.insert(freqMap[freq-1], Data(key, val, freq));
        }
        
        if (freqMap[freq-1]->key == key) {
            auto it = freqMap[freq-1];
            it++;
            if (it != d_list.end() && it->freq == freq -1) {
                freqMap[freq-1] = it;
            } else {
                freqMap.erase(freq-1);
            }
        }
        
        d_list.erase(keyMap[key]);
        keyMap[key] = iter;
        freqMap[freq] = iter;

        return val;
    }
    
    void put(int key, int value) {
        if (d_capacity == 0) {
            return;
        }

        if (!keyMap.count(key)) {
            if (d_list.size() == d_capacity) {
                auto last = d_list.back();
                if (freqMap[last.freq]->key == last.key) {
                    freqMap.erase(last.freq);
                }
                keyMap.erase(last.key);
                d_list.pop_back();
            }
            
            list<Data>::iterator iter;
            if (freqMap.count(1)) {
                iter = d_list.insert(freqMap[1], Data(key, value, 1));
            } else {
                iter = d_list.insert(d_list.end(), Data(key, value, 1));
            }
            keyMap[key] = iter;
            freqMap[1] = iter;
        } else {
            get(key, value);
        }
    }
private:
    struct Data {
        int key;
        int val;
        int freq;
        Data(int k, int v, int f) : key(k), val(v), freq(f) {}
    };
    
    int d_capacity;
    list<Data> d_list;
    unordered_map<int, list<Data>::iterator> keyMap;
    unordered_map<int, list<Data>::iterator> freqMap;
};
