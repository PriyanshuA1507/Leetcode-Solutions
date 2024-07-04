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
    ListNode* mergeNodes(ListNode* head) {
      ListNode* current = head->next; 
        ListNode* resultHead = new ListNode(0); 
        ListNode* resultTail = resultHead; 

        int sum = 0;
        while (current != nullptr) {
            if (current->val != 0) {
                sum += current->val;
            } else {
                resultTail->next = new ListNode(sum);
                resultTail = resultTail->next;
                sum = 0;
            }
            current = current->next;
        }

        return resultHead->next; 
    }
};