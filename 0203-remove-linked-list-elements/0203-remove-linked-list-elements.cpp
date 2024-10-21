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
    ListNode* removeElements(ListNode* head, int val) {
        // Base case: if the list is empty, return nullptr
        if (head == nullptr) {
            return nullptr;
        }

        // Recursively call removeElements on the next node
        head->next = removeElements(head->next, val);

        // If the current node's value matches the specified value, skip it
        if (head->val == val) {
            ListNode* temp = head->next;
            delete head; // Free the memory of the current node
            return temp; // Return the next node
        } else {
            return head; // Return the current node
        }
    }
};