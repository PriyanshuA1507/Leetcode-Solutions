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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp = reverseList(head->next);
        ListNode* a = temp;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = head;
        head->next = NULL;
        return a;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* b = reverseList(head);
        if(n==1){
         ListNode* temp = b;
         b=b->next;
         temp->next = NULL;
         delete temp;
        }
        else{
         ListNode* curr = b;
         ListNode* prev = NULL;
         int count = 1;
         while(count<n){
            prev = curr;
            curr = curr->next;
            count++;
         }
         prev->next = curr->next;
         curr->next = NULL;
         delete curr;
        }
        ListNode* c = reverseList(b);
        return c;
    }
};