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
    // Function to split the list into two halves
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    // Function to merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while(left && right) {
            if(left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if(left) tail->next = left;
        if(right) tail->next = right;

        return dummy.next;
    }

    // Function to sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        // Split the list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge the two sorted halves
        return merge(left, right);
    }
};
