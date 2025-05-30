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
 vector<vector<int>> ans;
 void dfs(TreeNode* root, int targetSum, vector<int>& currentPath) {
        if (!root) return;

        currentPath.push_back(root->val);

        if (!root->left && !root->right && root->val == targetSum) {
            ans.push_back(currentPath);
        }

        dfs(root->left, targetSum - root->val, currentPath);
        dfs(root->right, targetSum - root->val, currentPath);

        currentPath.pop_back();  
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
     
        vector<int> currentPath;
        dfs(root, targetSum, currentPath);
        return ans;
    }
};