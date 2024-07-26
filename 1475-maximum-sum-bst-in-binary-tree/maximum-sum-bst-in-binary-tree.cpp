class Solution {
public:
    class Info {
    public:
        int maxi;
        int mini;
        bool is_bst;
        long long sum;
    };

    Info solve(TreeNode* root, long long &max_sum) {
        if (root == nullptr) {
            return {INT_MIN, INT_MAX, true, 0};
        }

        Info left = solve(root->left, max_sum);
        Info right = solve(root->right, max_sum);

        Info curr_node;
        curr_node.sum = left.sum + right.sum + root->val;
        curr_node.maxi = std::max(root->val, right.maxi);
        curr_node.mini = std::min(root->val, left.mini);

        if (left.is_bst && right.is_bst && root->val > left.maxi && root->val < right.mini) {  // Fixed condition
            curr_node.is_bst = true;
        } else {
            curr_node.is_bst = false;
        }

        if (curr_node.is_bst) {
            max_sum = std::max(max_sum, curr_node.sum);
        }

        return curr_node;
    }

    int maxSumBST(TreeNode* root) {
        long long max_sum = 0;
        solve(root, max_sum);
        return static_cast<int>(max_sum);
    }
};