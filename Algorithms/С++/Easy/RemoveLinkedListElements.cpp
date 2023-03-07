

/*

Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, and return the new head.

*/


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        if (!head)
            return head;

        ListNode* temp = head;

        while (temp->next) {
            if (temp->next->val == val) {
                temp->next = temp->next->next; 
                // we don't delete the element,we just go through two element forward node
                // and save this element in temp->next
            }
            else {
                temp = temp->next;
                // or we just keep the elements as they were
            }
        }

        return head;
    }

};