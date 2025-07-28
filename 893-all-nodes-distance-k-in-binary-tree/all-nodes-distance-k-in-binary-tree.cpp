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
   unordered_map<TreeNode*, TreeNode*> parent;
   void addparent(TreeNode* root){
   if(!root){
    return;
   }

   if(root->left)
   parent[root->left] = root;
   addparent(root->left);

   if(root->right)
   parent[root->right] = root;
   addparent(root->right);
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    addparent(root);
    vector<int> result;
    queue<TreeNode*> q;
    
    unordered_set<int> visited;
    
         q.push(target);
        visited.insert(target->val);

    while(q.size()!=0){
    int n = q.size();
    if(k==0){
        break;
    }
    while(n--){
    TreeNode* curr = q.front();
    q.pop();

    if(curr->left && !visited.count(curr->left->val)){
    q.push(curr->left);
    visited.insert(curr->left->val);
    }

    if(curr->right && !visited.count(curr->right->val)){
    q.push(curr->right);
    visited.insert(curr->right->val);
    }

    if(parent.count(curr) && !visited.count(parent[curr]->val)){
    q.push(parent[curr]);
    visited.insert(parent[curr]->val);
    }
    }
    k--;
    }

    while(q.size()!=0){
    TreeNode* temp = q.front();
    q.pop();
    result.push_back(temp->val);
    }
    return result;
    }
};