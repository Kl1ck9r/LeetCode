 /*
    Given the head of a linked list, rotate the list to the right by k places.
*/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode *current = head;
        int sz = 1;

        while(current->next) {
            sz++;
            current = current->next;
        }

        current->next = head;
        k = k % sz;

        while(--sz>=k) {
            current = current->next;
        }

        ListNode *newHead = current->next;
        current->next = nullptr;

        return newHead;
    }
};
