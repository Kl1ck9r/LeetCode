

/*

Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

*/


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return nullptr;

		ListNode* current = head;
		ListNode* p = head->next;

		while (p != nullptr) {
			if (current->val == p->val) {
				current->next = p->next;
				delete p;
				p = current->next;
			}
			else {
				current = p;
				p = p->next;
			}
		}
		return head;
	}
};