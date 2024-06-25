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
    void travel(TreeNode* root, int& sum){
        if(!root)
         return;

         travel(root->right,sum);
         root->val= sum+root->val;
         sum = root->val;
         travel(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        travel(root,sum);
        return root;
    }
};