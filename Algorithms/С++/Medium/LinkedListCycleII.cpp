    /*
         Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
        There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
        Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
        It is -1 if there is no cycle. Note that pos is not passed as a parameter.
        Do not modify the linked list.
    */



class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
        ListNode* hare = head;
        ListNode* turtle  = head;

        while(hare!=nullptr && hare->next!=nullptr) {
            turtle = turtle->next;
            hare = hare->next->next;

        if(turtle == hare) {
            ListNode* t1_node = head;
            ListNode* turtle_t1 = turtle;
            while(t1_node!=turtle_t1) {
                t1_node = t1_node->next;
                turtle_t1 = turtle_t1->next;
            }

            return t1_node;
        }
    }

        return nullptr;

	}
};
