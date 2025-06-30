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
    ListNode* hasCycle(ListNode *head) {
    
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return slow;
        }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
     ListNode* intersection = hasCycle(head);
     if(!intersection){
        return NULL;
     }  
     ListNode* slow = head;
     while(slow!=intersection){
      slow = slow->next;
      intersection = intersection->next;
     } 
     return slow;
    }
};