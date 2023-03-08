
/*
Given the head of a linked list, return the list after sorting it in ascending order
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) 
            return head;
        
        ListNode* node = head;
        vector<int> answ;

        while (node) {
            answ.push_back(node->val);
            node = node->next;
        }

        //O(n^2) selection sort
        for (size_t i = 0u; i < answ.size(); ++i) {
            size_t min = i;
            for (size_t j = i + 1u; j < answ.size(); ++j) {
                if (answ[j] < answ[min]) {
                    min = j;
                    swap(answ[i], answ[min]);
                }
            }
        }

        node = head;
        size_t index = 0;

        while (node) {
            node->val = answ[index++];
            node = node->next;
        }

        return head;
    }
};