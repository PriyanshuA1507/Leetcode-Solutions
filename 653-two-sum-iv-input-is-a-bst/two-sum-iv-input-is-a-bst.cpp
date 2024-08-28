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
   void inorder(TreeNode* root, vector<int>& a){
    if(!root){
        return;
    }
    inorder(root->left,a);
    a.push_back(root->val);
    inorder(root->right,a);
   }
    bool findTarget(TreeNode* root, int k) {
       vector<int> a;
       inorder(root,a);
       int start = 0;
       int end = a.size()-1;
       while(start<end){
      int sum = a[start]+a[end];
      if(sum==k){
        return true;
      }
      if(sum>k){
        end--;
      }
      else{
        start++;
      }
       }
       return false; 
    }
};