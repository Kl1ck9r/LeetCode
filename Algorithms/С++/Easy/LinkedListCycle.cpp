/*

	Given head, the head of a linked list, determine if the linked list has a cycle in it.
	There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
	following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
	Note that pos is not passed as a parameter.
	Return true if there is a cycle in the linked list. Otherwise, return false.

*/


class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head)
            return false;

        ListNode* node_f = head; 
        ListNode* node_s = head;

        while (node_f != nullptr && node_f->next != nullptr) {
            node_f = node_f->next->next;
            node_s = node_s->next;

            if (node_s == node_f) {
                return true;
            }
        }
        return false;
    }
};