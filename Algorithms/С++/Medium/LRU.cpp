/*
    Спроектируйте структуру данных, которая соответствует ограничениям кэша наименее недавно использованного (LRU) .
    Реализуйте LRUCacheкласс:

    LRUCache(int capacity)Инициализируйте кэш LRU с положительным размером capacity.
    int get(int key)Верните значение, keyесли ключ существует, в противном случае верните -1.
    void put(int key, int value)Обновите значение, keyесли keyсуществует. В противном случае добавьте key-valueпару в кеш. Если количество ключей превышает количество ключей capacityв этой операции, исключите ключ, который использовался реже всего.
    Каждая из функций getи putдолжна выполняться со O(1)средней временной сложностью.

    Пример 1:

    Вход
    ["LRUCache", "поместить", "поместить", "получить", "поместить", "получить", "поместить", "получить", "получить", "получить"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Выход
    [ноль, ноль, ноль, 1, ноль, -1, ноль, -1, 3, 4]

    Объяснение
    LRUCache lRUCache = новый LRUCache(2);
    lRUCache.put(1, 1); // кэш равен {1=1}
    lRUCache.put(2, 2); // кэш равен {1=1, 2=2}
    lRUCache.get(1); // возвращаем 1
    lRUCache.put(3, 3); // Ключ LRU был 2, вытесняет ключ 2, кеш равен {1=1, 3=3}
    lRUCache.get(2); // возвращает -1 (не найден)
    lRUCache.put(4, 4); // Ключ LRU был 1, вытесняет ключ 1, кеш равен {4=4, 3=3}
    lRUCache.get(1); // возвращаем -1 (не найдено)
    lRUCache.get(3); // возвращаем 3
    lRUCache.get(4); // возвращаем 4
*/


struct DoubleList {
    DoubleList* next;
    DoubleList*prev;
    int lru_data;
    int lru_key;

    DoubleList(int t_data) : lru_data(t_data),next(nullptr),prev(nullptr) { }

    DoubleList(int t_data,int t_key) : lru_data(t_data),lru_key(t_key),next(nullptr),prev(nullptr) { }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        lru_capacity = { capacity };
        front->next = rear;
        rear->prev = front;
    }

    int get(int key) {
        if(umap.find(key)==umap.end()) {
            return -1;
        }

        DoubleList *curr = umap[key];
        deleteNode(curr);
        addNode(curr);
        return curr->lru_data;
    }

    void put(int key, int value) {
        if(umap.find(key)!=umap.end()) {
            deleteNode(umap[key]);
        }

        if(umap.size() == lru_capacity) {
            deleteNode(rear->prev);
        }

        addNode(new DoubleList(value,key));
    }

private:
    void addNode(DoubleList *newNode) {
        newNode->next = front->next;
        front->next->prev = newNode;
        front->next = newNode;
        newNode->prev = front;
        umap[newNode->lru_key] = newNode;
    }

    void deleteNode(DoubleList *newNode) {
        umap.erase(newNode->lru_key);
        newNode->next->prev = newNode->prev;
        newNode->prev->next = newNode->next;
    }

private:
    DoubleList *rear = new DoubleList(0,0),*front = new DoubleList(0,0);
    unordered_map<int,DoubleList*> umap;
    int lru_capacity = { 0 };
};
