/*
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
Return the head of the linked list after doubling it.

Example 1:

Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:

Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.
*/



// recursion way
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        int result = multiply(head);
        if(result) head = new ListNode(result,head);
        return head;
    }

    int multiply(ListNode *head) {
        if(!head) return 0;
        int num = head->val * 2 + multiply(head->next);
        head->val = num %10;
        return num/10;
    }
};

// string way
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        ListNode *current = head,*p = nullptr;
        string num = "";

        while(current) {
            num += to_string(current->val);
            current = current->next;
        }

        reverse(num.begin(), num.end());

        string res = "";
        int carry = 0;

        for(int i=0;i<num.size();i++) {
            int digit = num[i] - '0';
            int prod = digit * 2 + carry;
            carry = prod / 10;
            prod = prod % 10;
            res += to_string(prod);
        }


        if(carry > 0) {
            res += to_string(carry);
        }

        reverse(res.begin(), res.end());

        ListNode* dummy = new ListNode(res[0] - '0');
        p = dummy;

        for(int i=1;i<res.size();i++) {
            p->next = new ListNode(res[i] - '0');
            p = p->next;
        }

        return dummy;
    }
};

