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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            return handleDeletion(root);
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

private:
    TreeNode* handleDeletion(TreeNode* root) {
        // 0 children
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // 1 child (right)
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        // 1 child (left)
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // 2 children
        int min_val = findMin(root->right)->val;
        root->val = min_val;
        root->right = deleteNode(root->right, min_val);
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};