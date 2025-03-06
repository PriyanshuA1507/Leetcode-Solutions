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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        // Count the nodes
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // If we have at least k nodes, then we reverse
        if (count == k) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;
            int i = 0;
            
            while (curr != NULL && i < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                i++;
            }

            // Recursively process the remaining list
            head->next = reverseKGroup(curr, k);
            
            return prev; // New head of the reversed group
        }

        // If there are fewer than k nodes left, return head as is (no reversal)
        return head;
    }
};
