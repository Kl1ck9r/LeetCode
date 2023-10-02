/*
    Design a HashSet without using any built-in hash table libraries.

    Implement MyHashSet class:

    void add(key) Inserts the value key into the HashSet.

    bool contains(key) Returns whether the value key exists in the HashSet or not.

    void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/



// first not best way(deque way)
class MyHashSet {
public:
    MyHashSet() { }

    void add(int key) {
        int idx = hash(key);
        for (auto it = vset[idx].begin(); it != vset[idx].end(); ++it) {
            if (*it == key) return;
        }
        vset[idx].push_back(key);
    }


    void remove(int key) {
        int idx = hash(key);
        for (auto it = vset[idx].begin(); it != vset[idx].end(); ++it) {
            if (*it == key) {
                vset[idx].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int idx = hash(key);
        for(auto it = vset[idx].begin();it!=vset[idx].end();++it) {
            if(*it == key) return true;
        }
        return false;
    }
private:
    int hash(int key) {
        return key % 10000;
    }

private:
    deque<int> vset[10000];
};

// second way more effective
class MyHashSet {
public:
    MyHashSet() {
        vset.resize(TABLE_SIZE);
    }

    void add(int key) {
        int hashIdx = hash_func(key);
        for(auto it = vset[hashIdx].begin();it!=vset[hashIdx].end();++it) {
            if(*it == key) return;
        }
        vset[hashIdx].push_back(key);
    }


    void remove(int key) {
        int hashIdx = hash_func(key);
        for(auto it = vset[hashIdx].begin();it!=vset[hashIdx].end();++it) {
            if(*it == key) {
                vset[hashIdx].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int hashIdx = hash_func(key);
        for(auto it = vset[hashIdx].begin();it!=vset[hashIdx].end();++it) {
            if(*it==key) return true;
        }

        return false;
    }

private:
    int hash_func(int key) {
        hash<int> hasher;
        size_t hash = hasher(key);
        size_t index = hash % TABLE_SIZE;
        return (int)index;
    }

private:
    static const size_t TABLE_SIZE = 100;
    vector<list<int>> vset;
};
