
/*

Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

*/

// beats 100% & memory 7.6MB 
// Time complexity: O(N)
// Auxiliary Space : O(1)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return head;

        ListNode* first = head; // here will be first number 

        while (first && first->next) {
            swap(first->val, first->next->val);

            first = first->next->next; // here we will go to forward to get two number and swap these
        }
        return head;
    }
};
