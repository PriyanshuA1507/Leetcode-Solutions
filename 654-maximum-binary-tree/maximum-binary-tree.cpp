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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if (nums.empty()) {
            return nullptr;
        }

        int maxi = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[maxi] < nums[i]) {
                maxi = i;
            }
        }

        TreeNode* a = new TreeNode(nums[maxi]);
        vector<int> b(nums.begin(), nums.begin() + maxi);
        vector<int> c(nums.begin() + maxi + 1, nums.end());

        a->left = constructMaximumBinaryTree(b);
        a->right = constructMaximumBinaryTree(c);
        return a;
    }
};