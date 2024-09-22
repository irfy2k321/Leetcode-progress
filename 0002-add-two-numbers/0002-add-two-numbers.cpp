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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();  // Dummy head to simplify edge cases
        ListNode* current = dummyHead;
        int carry = 0;  // Variable to keep track of the carry

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;  // Add the value from l1
                l1 = l1->next;   // Move to the next node in l1
            }

            if (l2 != nullptr) {
                sum += l2->val;  // Add the value from l2
                l2 = l2->next;   // Move to the next node in l2
            }

            carry = sum / 10;  // Calculate carry for the next iteration
            current->next = new ListNode(sum % 10);  // Add the current digit to the new list
            current = current->next;  // Move to the next node in the result list
        }

        return dummyHead->next;  // Return the result list starting from the node after dummy
    }
};