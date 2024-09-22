/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr; // If either list is null, there's no intersection
        }

        // Step 1: Calculate the lengths of both lists
        ListNode *a = headA;
        ListNode *b = headB;
        int lenA = 0, lenB = 0;

        while (a) {
            lenA++;
            a = a->next;
        }

        while (b) {
            lenB++;
            b = b->next;
        }

        // Step 2: Adjust the starting point of the longer list
        a = headA;
        b = headB;

        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                a = a->next; // Move pointer of the longer list
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                b = b->next; // Move pointer of the longer list
            }
        }

        // Step 3: Traverse both lists together to find the intersection
        while (a && b) {
            if (a == b) {
                return a; // Found the intersection
            }
            a = a->next;
            b = b->next;
        }

        return nullptr; // No intersection found
    }
};