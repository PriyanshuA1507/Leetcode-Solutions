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
     unordered_map<TreeNode*,int> memset;
     int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        if(memset[root]>0){
            return memset[root];
         }
      int taken = root->val;
        if (root->left) {
            taken += solve(root->left->left) + solve(root->left->right);
        }
        if (root->right) {
            taken += solve(root->right->left) + solve(root->right->right);
        }

        
        int nottaken = solve(root->left) + solve(root->right);

        return memset[root]=max({taken,nottaken});
     }
    int rob(TreeNode* root) {
        return solve(root);
    }
};