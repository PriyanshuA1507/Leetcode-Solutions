class Solution {
public:
    int solve(TreeNode* root, long long ts) {
        if (!root) return 0;

        int count = 0;
        if (root->val == ts) count++;

        count += solve(root->left, ts - root->val);
        count += solve(root->right, ts - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int total = solve(root, targetSum);           // Paths starting from current node
        total += pathSum(root->left, targetSum);      // Paths starting from left subtree
        total += pathSum(root->right, targetSum);     // Paths starting from right subtree

        return total;
    }
};
