/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildgraph(TreeNode* root,unordered_map<int,vector<int>>&adj){
       if(!root){
           return;
       }
      if(root->left){
     adj[root->val].emplace_back(root->left->val);
     adj[root->left->val].emplace_back(root->val);
     buildgraph(root->left,adj);
      }
      if(root->right){
     adj[root->val].emplace_back(root->right->val);
     adj[root->right->val].emplace_back(root->val);
     buildgraph(root->right,adj);
      }
      
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     if(!root){
        return {};
     }
       unordered_map<int,vector<int>>adj;
       buildgraph(root,adj);
       unordered_map<int, bool> vis;
       vis[target->val] = true;
       queue<int> q;
       q.push(target->val);
      vector<vector<int>> ans;
       while(q.size()!=0){
        int size = q.size();
        vector<int> a;
        for(int i=0;i<size;i++){
        int node = q.front();
        a.push_back(node);
        q.pop();
        for( auto a2: adj[node]){
        if(!vis[a2]){
            vis[a2] = true;
            q.push(a2);
        }
        }
        }
      ans.push_back(a);
       }
       if(ans.size()>=k){
        return ans[k];
       }
      return {};
    }
};