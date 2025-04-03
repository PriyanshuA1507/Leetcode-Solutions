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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
      map<int ,map<int,vector<int>>>nodes;
      queue<pair<TreeNode*,pair<int,int>>>q;
      if(!root){
        return ans;
      }
      q.push(make_pair(root,make_pair(0,0)));
      while(!q.empty()){
       auto a = q.front();
       q.pop();
       TreeNode* frontnode = a.first;
       int hd = a.second.first;
       int lvl = a.second.second;

       nodes[hd][lvl].push_back(frontnode->val);
       if(frontnode->left){
      q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
       }
        if(frontnode->right){
      q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
       }
    }

  for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                sort(j.second.begin(), j.second.end());  
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }

    return ans;
    }
};