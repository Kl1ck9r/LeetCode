/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.
*/



class MinStack {
private:
    struct Node {
        int data;
        Node *next;
        Node *prev;
        Node(int d,Node *t_next = nullptr,Node *t_prev = nullptr) :
            data(d),next(t_next),prev(t_prev) { }
    };

    Node *head;
    Node *tail;

public:
    MinStack() : head(nullptr), tail(nullptr) {

    }

    ~MinStack() {
        while(head!=nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int val) {
        Node *newNode = new Node(val,head,nullptr);
        if(head!=nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void pop() {
        if(head == nullptr) {
            return;
        }

        int data = head->data;
        Node *temp = head;
        head = head->next;

        if(head!=nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    int top() {
        if(head!=nullptr) {
            return head->data;
        } else {
            return 0;
        }
    }

    int getMin() {
        Node *current  = head;
        int minVal = current->data;

        while(current!=nullptr) {
            if(current->data<minVal) {
                minVal = current->data;
            }
            current = current->next;
        }

        return minVal;
    }
};
