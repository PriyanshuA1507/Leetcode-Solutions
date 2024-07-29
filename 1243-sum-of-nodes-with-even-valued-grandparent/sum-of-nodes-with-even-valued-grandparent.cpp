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
    void solve(TreeNode* root,int parent,int grandparent, int &sum){
        if(!root){
            return;
        }
     if(grandparent%2==0) sum+=root->val;
     solve(root->left,root->val,parent,sum);
     solve(root->right,root->val,parent,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int parent = -1, grandparent = -1;
        int sum=0;
        if(!root){
            return 0;
        }
        solve(root,parent,grandparent,sum);
        return sum;
    }
};