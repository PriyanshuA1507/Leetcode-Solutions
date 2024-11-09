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
 // If `a` reaches the end of list A, switch it to the start of list B.
            a = (a == nullptr) ? headB : a->next;
 // If `b` reaches the end of list B, switch it to the start of list A.
            b = (b == nullptr) ? headA : b->next;
        }

      // If lists intersect, `a` and `b` will eventually meet at the intersection node.
     // If no intersection, both `a` and `b` will reach nullptr simultaneously.
        return a;
    }
};