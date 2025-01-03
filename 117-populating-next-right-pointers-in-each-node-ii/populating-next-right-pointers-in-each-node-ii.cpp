/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
     queue<Node*> q;
     q.push(root);
     while(q.size()!=0){
      int a = q.size();
      Node* prev = NULL;
      for(int i=0;i<a;i++){
       Node* b = q.front();
       q.pop();
       if(prev){
        prev->next = b;
       }
       prev = b;
       if(b->left) q.push(b->left);
       if(b->right) q.push(b->right);
      }
      if(prev){
        prev->next = NULL;
      }
     }
     return root;   
    }
};