
class LRUCache{
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> um;
    int capacity;

public:
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        this->capacity = capacity;
    }

    int get(int key) {
        if(um.find(key) == um.end())
            return -1;
        pair<int, int> temp = {um[key]->first, um[key]->second};
        dq.erase(um[key]);
        um.erase(key);
        dq.push_front(temp);
        um[key] = dq.begin();
        return um[key]->second;
    }

    void put(int key, int value) {
        if(dq.size() < capacity){
            if(um.find(key) == um.end()){
                dq.push_front({key, value});
                um[key] = dq.begin();
            }
            else if(um.find(key) != um.end()){
                dq.erase(um[key]);
                um.erase(key);
                dq.push_front({key, value});
                um[key] = dq.begin();
            }
        }
        else{
            if(um.find(key) != um.end()){
                dq.erase(um[key]);
                um.erase(key);
                dq.push_front({key, value});
                um[key] = dq.begin();
            }
            else{
                int temp = dq.back().first;
                um.erase(temp);
                dq.pop_back();
                dq.push_front({key, value});
                um[key] = dq.begin();
            }
        }
    }
};
