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
    void deleteNode(int position, ListNode* & head) { 
    if(position == 1) {
       ListNode* temp = head;
        head = head -> next;

        temp -> next = NULL;
        delete temp;
    }
    else
    {
        ListNode* curr = head;
       ListNode* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}
    ListNode* deleteMiddle(ListNode* head) {
     int l = 0;
     ListNode* a = head;
     while(a!=NULL){
        a = a->next;
        l++;
     }
     deleteNode((l/2)+1,head);
     return head;   
    }
};