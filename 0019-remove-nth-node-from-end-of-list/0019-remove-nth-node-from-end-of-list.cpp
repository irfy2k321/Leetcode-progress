/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);  // Create a dummy node pointing to head
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Now, second is at the node before the one we want to delete
        ListNode* toDelete = second->next;
        second->next = toDelete->next;  // Bypass the node to delete
        delete toDelete;  // Free the memory of the node to delete

        ListNode* newHead = dummy->next;  // Update head in case it was deleted
        delete dummy;  // Clean up dummy node

        return newHead;  // Return the updated head
    }
};