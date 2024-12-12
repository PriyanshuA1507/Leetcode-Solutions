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
        queue<TreeNode*> q;
       vector<vector<int>> ans;
       if(!root){
        return ans;
       }
       q.push(root);
       while(q.size()!=0){
        int a = q.size();
        vector<int> c;
        for(int i=0;i<a;i++){
        TreeNode* b = q.front();
        c.push_back(b->val);
        q.pop();
         if(b->left){
         q.push(b->left);
         }
         if(b->right){
            q.push(b->right);
         }
        }
        ans.push_back(c);
       }
       return ans;
    }
};