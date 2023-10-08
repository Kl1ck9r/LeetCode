/*
    Design your implementation of the circular double-ended queue (deque).

    Implement the MyCircularDeque class:

    MyCircularDeque(int k) Initializes the deque with a maximum size of k.
    boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
    int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
    int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
    boolean isEmpty() Returns true if the deque is empty, or false otherwise.
    boolean isFull() Returns true if the deque is full, or false otherwise.

    Example 1:

    Input
    ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
    [[3], [1], [2], [3], [4], [], [], [], [4], []]
    Output
    [null, true, true, true, false, 2, true, true, true, 4]

    Explanation
    MyCircularDeque myCircularDeque = new MyCircularDeque(3);
    myCircularDeque.insertLast(1);  // return True
    myCircularDeque.insertLast(2);  // return True
    myCircularDeque.insertFront(3); // return True
    myCircularDeque.insertFront(4); // return False, the queue is full.
    myCircularDeque.getRear();      // return 2
    myCircularDeque.isFull();       // return True
    myCircularDeque.deleteLast();   // return True
    myCircularDeque.insertFront(4); // return True
    myCircularDeque.getFront();     // return 4
*/


class DoubleLinkList final {
public:
    DoubleLinkList() :  next(nullptr),prev(nullptr) { }

    DoubleLinkList(int t_data) : data(t_data),next(nullptr),prev(nullptr) { }

public:
    int data;
    DoubleLinkList *next;
    DoubleLinkList *prev;
};

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        max_size = k;
    }

    bool insertFront(int value) {
        if(isFull())
            return false;

        DoubleLinkList *newNode = new DoubleLinkList(value);

        if(isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        t_size++;

        return true;
    }

    bool insertLast(int value) {
        if(isFull())
            return false;

        DoubleLinkList *newNode = new DoubleLinkList(value);

        if(isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        t_size++;

        return true;
    }

    bool deleteFront() {
        if(isEmpty())
            return false;

        if(front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        t_size--;

        return true;
    }

    bool deleteLast() {
        if(isEmpty())
            return false;

        if(front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
        }
        t_size--;

        return true;
    }

    int getFront() {
       return front == nullptr ? -1 : front->data;
    }

    int getRear() {
       return rear == nullptr ? -1 : rear->data;
    }

    bool isEmpty() {
       return t_size == 0;
    }

    bool isFull() {
       return t_size == max_size;
    }

private:
    DoubleLinkList *front = nullptr;
    DoubleLinkList *rear = nullptr;
    int t_size = { 0 };
    int max_size = { 0 };
};

