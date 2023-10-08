/*
    You are given the head of a linked list.
    Remove every node which has a node with a greater value anywhere to the right side of it.
    Return the head of the modified linked list.

    Example 1:

    Input: head = [5,2,13,3,8]
    Output: [13,8]
    Explanation: The nodes that should be removed are 5, 2 and 3.
    - Node 13 is to the right of node 5.
    - Node 13 is to the right of node 2.
    - Node 8 is to the right of node 3.

    Example 2:

    Input: head = [1,1,1,1]
    Output: [1,1,1,1]
    Explanation: Every node has value 1, so no nodes are removed.
*/


// first way
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
      ListNode *current = head;
      ListNode *prev = nullptr;
      removeNodesHelper(prev,current,head);
      return head;
}

private:
void removeNodesHelper(ListNode *prev,ListNode *curr,ListNode* &head) {
    if(!curr->next) {
        head = curr;
        return;
    }

    removeNodesHelper(curr,curr->next,head);

    if(curr->val<head->val) {
        if(prev) prev->next = curr->next;
        curr->next = nullptr;
    } else {
        head = curr;
    }
}
};


// second way
class Solution {
public:
ListNode* removeNodes(ListNode* head) {
    if(head == nullptr)
        return nullptr;

    stack<ListNode*> st;
    ListNode *current = head,*newHead;
    st.push(current);
    current = current->next;

    while(current) {
        while(current && st.size() && st.top()->val < current->val) {
            st.pop();
        }

        if(st.size() == 0 ){
            newHead = current;
        } else {
            st.top()->next = current;
        }

        st.push(current);
        current = current->next;
    }
    return newHead;
}
};
