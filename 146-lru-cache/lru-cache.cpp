class LRUCache {
    int cap;
    list<pair<int,int>> dl;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        dl.splice(dl.begin(), dl, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            dl.splice(dl.begin(), dl, mp[key]);
        } else {
            if (dl.size() == cap) {
                mp.erase(dl.back().first);
                dl.pop_back();
            }
            dl.push_front({key, value});
            mp[key] = dl.begin();
        }
    }
};