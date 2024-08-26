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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root){
            return ans;
        }
        q.push(root);
        while(q.size()!=0){
        int size = q.size();
        vector<int> level;
        while(size-->0){
         auto a = q.front();
         level.push_back(a->val);
         if(a->left){
          q.push(a->left);
         } 
         if(a->right){
          q.push(a->right);
         }
         q.pop(); 
        }
        ans.push_back(level);
        }
        return ans;
    }
};