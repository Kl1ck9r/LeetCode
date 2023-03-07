
/*

Given the head of a singly linked list, return true if it is a palindromeor false otherwise.

*/

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head)
			return head;

		vector<int> answ;
		vector<int> check;
		while (head) {
			answ.push_back(head->val);
			check.push_back(head->val);
			head = head->next;
		}

		std::reverse(answ.begin(), answ.end());

		bool result = std::equal(answ.begin(), answ.end(), check.begin());

		return result;

	}
};
