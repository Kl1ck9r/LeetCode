
/*
	You are given the heads of two sorted linked lists list1 and list2.
	Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
	Return the head of the merged linked list.
*/



class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* res = new  ListNode(0); // dummy node created
		ListNode* current = res; 

		while (true) {
			if (l1 == nullptr) {
				current->next = l2;
				break;
			}
			if (l2 == nullptr) {
				current->next = l1;
				break;
			}

			if (l1->val < l2->val) {
				current->next = l1;
				l1 = l1->next;
			}
			else {
				current->next = l2;
				l2 = l2->next;
			}
			current = current->next;
		}

		return res->next;
	}
};