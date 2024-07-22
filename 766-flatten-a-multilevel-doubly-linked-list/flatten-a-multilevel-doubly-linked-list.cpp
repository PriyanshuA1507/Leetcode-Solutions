/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
    Node* curr = head;
        
        while (curr != NULL) {
            if (curr->child) {
                Node* child = curr->child;
                Node* next = curr->next;
                
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;
                
                Node* childTail = child;
                while (childTail->next) {
                    childTail = childTail->next;
                }
                
                childTail->next = next;
                if (next) {
                    next->prev = childTail;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};