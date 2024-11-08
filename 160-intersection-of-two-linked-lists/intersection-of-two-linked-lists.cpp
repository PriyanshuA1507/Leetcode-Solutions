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
      if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        ListNode *a = headA;
        ListNode *b = headB;

        // Traverse both lists. When reaching the end of one list, continue from the beginning of the other.
        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        // Either intersection node or nullptr if no intersection.
        return a;
    }
};