 



struct DoubleNode {
    DoubleNode *next;
    DoubleNode *prev;
    int data;

    DoubleNode(): next(nullptr), prev(nullptr) { }

    DoubleNode(int t_data) : data(t_data), next(nullptr), prev(nullptr)  { }
};

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        DoubleNode *newNode = new DoubleNode(val);
        if(front == nullptr) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }
    void pushMiddle(int val) {
        DoubleNode *turtle = front, *rabbit = front, *newNode = new DoubleNode(val);

        if (front == nullptr) {
            front = rear = newNode;
        } else if (front->next == nullptr) {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        } else {
            while (rabbit != nullptr && rabbit->next != nullptr) {
                turtle = turtle->next;
                rabbit = rabbit->next->next;
            }

            newNode->prev = turtle->prev;
            newNode->next = turtle;
            if (turtle->prev) turtle->prev->next = newNode;
            else front = newNode;
            turtle->prev = newNode;
        }
    }

    void pushBack(int val) {
        DoubleNode *newNode = new DoubleNode(val);
        if(front == nullptr) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int popFront() {
        if(!front)
            return -1;

        int rm_data = front->data;
        DoubleNode *temp = front;

        if(front->next) {
            front->next->prev = nullptr;
            front = front->next;
        } else {
            front = rear = nullptr;
        }

        delete temp;
        return rm_data;
    }

    int popMiddle() {
        if (!front)
            return -1;

        DoubleNode *turtle = front;
        DoubleNode *rabbit = front;

        while (rabbit->next && rabbit->next->next) {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }

        int rm_data = turtle->data;

        if (turtle->next)  {
            turtle->next->prev = turtle->prev;
        } else {
            rear = turtle->prev;
        }

        if (turtle->prev) {
            turtle->prev->next = turtle->next;
        } else {
            front = turtle->next;
        }

        delete turtle;
        return rm_data;
    }


    int popBack() {
        if(!rear)
            return -1;

        int rm_data = rear->data;
        DoubleNode *temp = rear;

        if(!rear->prev) {
            front = rear = nullptr;
        } else {
            rear->prev->next = nullptr;
            rear = rear->prev;
        }

        delete temp;
        return rm_data;
    }

private:
    DoubleNode *rear = nullptr;
    DoubleNode *front = nullptr;
};
