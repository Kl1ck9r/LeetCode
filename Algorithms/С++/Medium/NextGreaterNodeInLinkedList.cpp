/*
You are given the head of a linked list with n nodes.
For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

Example 1:

Input: head = [2,1,5]
Output: [5,5,0]

Example 2:

Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
*/


class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        if (head == nullptr)
            return {};

        vector<int> result;

        while (head->next) {
            int count;
            ListNode *front = head->next;
            while (front) {
                count = 0;
                if (head->val < front->val) {
                    result.push_back(front->val);
                    count++;
                    break;
                }
                front = front->next;
            }
            if (count == 0)
                result.push_back(0);

            head = head->next;
        }

        result.push_back(0);

        return result;
    }
};

