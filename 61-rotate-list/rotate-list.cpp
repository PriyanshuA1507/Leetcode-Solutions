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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){return head;}
       int size=1;
       ListNode* a = head;
       while(a->next){
        a=a->next;
        size++;
       }
       k=k%size;
       a->next = head;
       a = head;
       for(int i=1;i<size-k;i++){
          a = a->next;
       }
       head= a->next;
        a->next= NULL;
        return head;
    }

};