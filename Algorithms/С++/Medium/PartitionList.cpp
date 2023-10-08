/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

*/


// first way
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode *current = head;
        ListNode *lessNode = nullptr;
        ListNode *lessNodeHead = nullptr;
        ListNode *moreNode = nullptr;
        ListNode *moreNodeHead = nullptr;

        while(current)  {
            ListNode *next = current->next;
            current->next = nullptr;
            if(current->val < x) {
                if(lessNode == nullptr) {
                    lessNode = current;
                    lessNodeHead = current;
                } else {
                    lessNode->next = current;
                    lessNode = lessNode->next;
                }

            } else if(current->val>=x) {
                if(moreNode == nullptr) {
                    moreNode = current;
                    moreNodeHead = current;
                } else {
                    moreNode->next = current;
                    moreNode = moreNode->next;
                }
            }
            current = next;
        }

        if(lessNode) {
            lessNode->next = moreNodeHead;
        } else {
            return moreNodeHead;
        }

        if(moreNode) {
            moreNode->next = nullptr;
        }

        return lessNodeHead;
    }
};


// second way
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode *large = new ListNode(-1);
        ListNode *small = new ListNode(-1);
        ListNode *smallHead = small;
        ListNode *largeHead = large;

        while(head) {
            if(head->val<x) {
                small->next = head;
                small = small->next;
                head = head->next;
                small->next = nullptr;
            } else {
                large->next = head;
                large = large->next;
                head = head->next;
                large->next = nullptr;
            }
        }

        small->next = largeHead->next;

        return smallHead->next;
    }
};
