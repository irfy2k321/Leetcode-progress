

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // If the list is empty or has only one node, or k is 0, return as is
        if (!head || !head->next || k == 0) return head;
        
        // Step 1: Find the length of the list and the last node
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Step 2: Normalize k
        k = k % length;
        if (k == 0) return head;  // No rotation needed
        
        // Step 3: Find the new tail (length - k)th node
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        
        // Step 4: Rotate the list
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        
        return newHead;
    }
};