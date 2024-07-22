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
    vector<string> stack;
    
    void dfs(TreeNode* root, string temp) {
        if (!root) {
            return;
        }
        temp += to_string(root->val);
        if (!root->right && !root->left) {
            stack.push_back(temp);
            return;
        }
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        string temp = "";
        dfs(root, temp);
        for (const auto& bs : stack) {
            sum += stoi(bs, nullptr, 2);
        }
        return sum;
    }
};