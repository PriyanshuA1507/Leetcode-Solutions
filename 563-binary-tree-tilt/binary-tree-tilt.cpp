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
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        sumAndTilt(root, totalTilt);
        return totalTilt;
    }

private:
    int sumAndTilt(TreeNode* node, int &totalTilt) {
        if (!node) return 0;
        int leftSum = sumAndTilt(node->left, totalTilt);
        int rightSum = sumAndTilt(node->right, totalTilt);
        totalTilt += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }
};