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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == nullptr)
        {
            return head;
        }
        ListNode *first = head;
        ListNode *second = head->next;
        while (first != nullptr && second != nullptr)
        {
            if(first->val == second->val)
            {
                first->next = second->next;
                ListNode* temp = second;
                second = first->next;
                delete temp;
            }
            else{
                first = first->next;
                second = first ? first->next : nullptr;
            }
        }
        return head;
    }
};