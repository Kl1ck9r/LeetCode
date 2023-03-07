
/*

Given the head of a singly linked list, 
reverse the list, and return the reversed list.

*/

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* reverse = nullptr;
		while (head) {
			ListNode* temp = head->next;
			head->next = reverse;
			reverse = head;
			head = temp;
		}
		return reverse;
	}
};