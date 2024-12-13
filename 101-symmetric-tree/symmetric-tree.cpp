/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   bool issame(TreeNode* a, TreeNode* b){
    if(!a && !b){
        return true;
    }
    if(a && !b){
        return false;
    }
    if(!a && b){
        return false;
    }
    if(a->val == b->val){
     return (issame(a->left,b->right) && issame(a->right,b->left));
    }
    return false;
   }
    bool isSymmetric(TreeNode* root) {
    return issame(root->left, root->right);
    }
};