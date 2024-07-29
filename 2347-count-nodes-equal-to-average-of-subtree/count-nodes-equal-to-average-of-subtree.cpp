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
     int cn(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1 + cn(root->left) + cn(root->right);
     }
     int ts(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val + ts(root->left) + ts(root->right);
     }
    int averageOfSubtree(TreeNode* root) {
        if(!root){
            return 0;
        }
      int a = root->val + ts(root->left) + ts(root->right);
      int c = 1 + cn(root->left) + cn(root->right);
      double a1= floor(a/c);
      if(a1==root->val){
         return 1 + averageOfSubtree(root->left)+averageOfSubtree(root->right); 
      }
       return averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
};