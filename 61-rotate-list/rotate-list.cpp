class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;


        int length = 1;
        ListNode* temp = head;
        while (temp->next) {
            length++;
            temp = temp->next;
        }

        // Connect the last node to the head to make it circular
        temp->next = head;

        // Update k to avoid unnecessary rotations
        k = k % length;
        int stepsToNewHead = length - k;

        // Find the new tail (the node before the new head)
        temp = head;
        for (int i = 0; i < stepsToNewHead - 1; i++) {
            temp = temp->next;
        }

        // Set the new head and break the loop
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};
