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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index,int inorderstart, int inorderend, int n,unordered_map<int,int>& m){
    if(index>=n || inorderstart>inorderend){
      return NULL;
    }
    int element = preorder[index++];
    TreeNode* root = new TreeNode(element);
    int position = m[element];
    root->left = solve(preorder,inorder,index,inorderstart,position-1,n,m);
    root->right = solve(preorder,inorder,index,position+1,inorderend,n,m);
    return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n = preorder.size();
       int pin = 0;
       unordered_map<int,int> m;
       for(int i=0;i<inorder.size();i++){
        m[inorder[i]] = i;
       }
       TreeNode* ans = solve(preorder,inorder,pin,0,n-1,n,m);
       return ans;
    }
};