/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
*/


struct LinkList {
    int val;
    LinkList *next;

    LinkList() : val(0),next(nullptr) { }

    LinkList(int t_val) :val(t_val),next(nullptr) { }
};

class MyLinkedList {
public:
    MyLinkedList() {

    }

    int get(int index) {
        if(index<0 || index>size)
            return -1;

        LinkList *curr = head;
        for(int i = 0;i<index && curr;i++)  {
            curr = curr->next;
        }

        return curr!=nullptr ? curr->val : -1;
    }

    void addAtHead(int val) {
        LinkList *newNode = new LinkList(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        LinkList *newNode = new LinkList(val);
        if(head == nullptr) {
            head = newNode;
        } else {
            LinkList *curr = head;
            while(curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index<0 || index>size) {
            return;
        } else if(index == 0)  {
            addAtHead(val);
            return;
        } else if(index == size) {
            addAtTail(val);
            return;
        }

        LinkList *newNode = new LinkList(val);
        LinkList *curr = head;

        for(int i = 0;i<index-1;i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index<0 || index>=size)
           return;

        LinkList *temp;
        if(index == 0 ) {
            temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        LinkList *curr = head;
        for(int i = 0;i<index-1;i++) {
            curr = curr->next;
        }

        temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }

private:
    LinkList *head = nullptr;
    int size = { 0 };
};
