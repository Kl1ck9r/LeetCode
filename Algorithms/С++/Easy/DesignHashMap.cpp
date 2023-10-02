/*
    Design a HashMap without using any built-in hash table libraries.
    Implement the MyHashMap class:

    MyHashMap() initializes the object with an empty map.
    void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
    int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

    Example 1:

    Input
    ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
    [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
    Output
    [null, null, null, 1, -1, null, 1, null, -1]

    Explanation
    MyHashMap myHashMap = new MyHashMap();
    myHashMap.put(1, 1); // The map is now [[1,1]]
    myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
    myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
    myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
*/


class MyHashMap {
public:
    MyHashMap() {
        vmap.resize(TABLE_SIZE);
    }

    void put(int key, int value) {
        int hashIdx = hash_func(key);
        auto& pairs = vmap[hashIdx];
        for(auto &it : pairs) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        pairs.push_back(make_pair(key,value));
    }

    int get(int key) {
        int hashIdx = hash_func(key);
        for(const auto it:vmap[hashIdx]) {
            if(it.first == key)
                return it.second;
        }
        return -1;
    }

    void remove(int key) {
        int hashIdx = hash_func(key);
        auto& pairs = vmap[hashIdx];
        for(auto it = pairs.begin(); it != pairs.end(); ++it) {
            if(it->first == key) {
                pairs.erase(it);
                break;
            }
        }
    }

private:
    int hash_func(int key) {
        hash<int> hasher;
        size_t hash = hasher(key);
        size_t index = hash % TABLE_SIZE;
        return (int)index;
    }

private:
    vector<list<pair<int, int>>> vmap;
    static const int TABLE_SIZE = 100;
};

