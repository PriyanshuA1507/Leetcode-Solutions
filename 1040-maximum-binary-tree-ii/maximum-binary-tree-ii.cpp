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
    void inorder(TreeNode* root,vector<int>& nums) {
    
    if(root == NULL) {
        return ;
    }

    inorder(root->left,nums);
     nums.push_back(root->val);
    inorder(root->right,nums);

}
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
       vector<int> nums;
       inorder(root,nums);
       nums.push_back(val);
       return constructMaximumBinaryTree(nums);
    }
};