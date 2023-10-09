/*
    You are given the head of a linked list, and an integer k.
    Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

    Example 1:

    Input: head = [1,2,3,4,5], k = 2
    Output: [1,4,3,2,5]

    Example 2:

    Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
    Output: [7,9,6,6,8,7,3,0,9,5]
*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;

        ListNode *k_node = head;
        for(int i = 0;i<k-1;i++) {
            k_node = k_node->next;
        }

        int nz = 0;
        ListNode *curr = head;
        while(curr) {
            nz++;
            curr = curr->next;
        }

        ListNode *k_node_last = head;
        for(int i = 0;i<nz-k;i++) {
            k_node_last = k_node_last->next;
        }

        int temp = k_node->val;
        k_node->val = k_node_last->val;
        k_node_last->val = temp;

        return head;
    }
};
