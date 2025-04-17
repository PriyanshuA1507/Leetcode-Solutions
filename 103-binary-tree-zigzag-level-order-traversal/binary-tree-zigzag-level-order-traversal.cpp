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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
        int a = q.size();
        vector<int> c;
        for(int i=0;i<a;i++){
        auto b = q.front();
        q.pop();
        c.push_back(b->val);

        if(b->left){
        q.push(b->left);
        }
        if(b->right){
        q.push(b->right);
        }
        }
        if(!flag){
        reverse(c.begin(),c.end());
        ans.push_back(c);
        }
        else{
         ans.push_back(c);
        }
        flag = !flag;
        }
        return ans;
    }
};