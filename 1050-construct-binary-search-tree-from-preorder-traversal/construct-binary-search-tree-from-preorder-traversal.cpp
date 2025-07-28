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
    TreeNode* solve(vector<int>& preorder,int& index,int mini,int maxi){
    if(index >= preorder.size()){
        return NULL;
    }
    if(preorder[index]<mini || preorder[index]>maxi){
    return NULL;
    }
   TreeNode* root = new TreeNode(preorder[index++]);
   root->left = solve(preorder,index,mini,root->val);
   root->right = solve(preorder,index,root->val,maxi);
   return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = -1e8, maxi = 1e8;
        int index = 0;
        return solve(preorder,index,mini,maxi);
    }
};