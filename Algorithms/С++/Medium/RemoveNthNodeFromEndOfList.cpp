/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* first_ptr = new_head;
        ListNode* second_ptr = new_head;

        for (int i = 0; i < n; i++) {
            if (first_ptr == nullptr) {
                return nullptr;
            }
            first_ptr = first_ptr->next;
        }

        while(first_ptr->next) {
            first_ptr = first_ptr->next;
            second_ptr = second_ptr->next;
        }

        ListNode *delete_node = second_ptr->next;
        second_ptr->next = second_ptr->next->next;
        delete delete_node;

        return new_head->next;
    }
};
