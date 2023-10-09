/*
Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Example 1:

Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

Example 2:

Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list
*/


// first way
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        ListNode *current = head,*newHead = nullptr,*newHeadTail = nullptr;
        vector<int> vec;

        while(current && current->next&& current->next) {
            int gcd = std::gcd(current->val,current->next->val);

            vec.push_back(current->val);
            vec.push_back(gcd);

            current = current->next;
        }

        if(current) vec.push_back(current->val);

        for(const int num:vec) {
            ListNode *newNode = new ListNode(num);
            if(newHead == nullptr) {
                newHead = newNode;
                newHeadTail = newNode;
            } else {
                newHeadTail->next = newNode;
                newHeadTail = newHeadTail->next;
            }
        }
        return newHead;
    }
};

// second way
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while(ptr->next){
            ListNode* temp = new ListNode(std::gcd(ptr->val, ptr->next->val),  ptr->next);
            ptr->next = temp;
            ptr = temp->next;
        }
        return head;
    }
};
