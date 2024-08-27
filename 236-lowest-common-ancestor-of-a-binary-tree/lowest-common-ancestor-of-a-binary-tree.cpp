/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
         TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
         if(leftans && rightans){
            return root;
         }
         if(leftans && !rightans){
            return leftans;
         }
         else if(rightans && !leftans){
            return rightans;
         }
         else 
         return NULL;
    }
};