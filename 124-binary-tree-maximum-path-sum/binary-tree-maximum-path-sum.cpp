class Solution {
public:
    int solve(TreeNode* root, int& maxsum) {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, solve(root->left, maxsum));
        int right = max(0, solve(root->right, maxsum));
        maxsum = max(maxsum, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(root, maxsum);
        return maxsum;
    }
};