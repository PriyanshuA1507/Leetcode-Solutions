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
     void solve(TreeNode* root, int distance,vector<int>& ld,int& tp){
        if(!root){
            return;
        }
        if (!root->left && !root->right) {
            ld.push_back(0);
            return;
        }
      vector<int> lnd,rnd;
      solve(root->left,distance,lnd,tp);
      solve(root->right,distance,rnd,tp);
      for(int i:lnd){
        for(int j:rnd){
            if(i+j+2<=distance){
                tp++;
            }
        }
      }
      for (int l : lnd) {
            ld.push_back(l + 1);
        }
        for (int r : rnd) {
            ld.push_back(r + 1);
        }
     }
    int countPairs(TreeNode* root, int distance) {
        vector<int> ld;
        int tp=0;
     solve(root,distance,ld,tp);
     return tp;
    }
};