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
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        queue<TreeNode*> a;
        a.push(root);
        bool ltor = true;
        while(!a.empty()){
            int size = a.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
            TreeNode* fn = a.front();
            a.pop();
            int index = ltor? i: size-i-1;
            ans[index] = fn->val;
            if(fn->left){
             a.push(fn->left);
            }
            if(fn->right){
                a.push(fn->right);
            }
            }
             ltor = !ltor;
            result.push_back(ans); 
        } 
        return result;
    }
};