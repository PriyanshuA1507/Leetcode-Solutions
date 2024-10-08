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
    ListNode *detectCycle(ListNode *head) {
        ListNode *a=NULL;
        if(!head || !head->next)
        return a;

        ListNode *slow = head;
        ListNode *fast = head;
        bool hascycle=false;

    while(fast && fast->next){

        slow= slow->next;
        fast= fast->next->next;

        if(slow==fast){
            hascycle=true;
            break;
        }
    }
   if(!hascycle)
   return NULL;

   slow=head;
   while(slow!=fast){
       slow=slow->next;
       fast=fast->next;
   }
  return slow;
    }
};