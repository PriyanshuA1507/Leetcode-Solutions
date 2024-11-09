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
       if(!head || !head->next){
        return head;
       } 
       int length = 1;
       ListNode* temp = head;
       while(temp->next){
        temp = temp->next;
        length++;
       }
      k = k%length;
     temp->next = head;
     int startingnode = length - k;
     temp = head;
     for(int i=1;i<startingnode;i++){
       temp = temp->next;
     }
     head = temp->next;
     temp->next = NULL;
     return head;

    }
};