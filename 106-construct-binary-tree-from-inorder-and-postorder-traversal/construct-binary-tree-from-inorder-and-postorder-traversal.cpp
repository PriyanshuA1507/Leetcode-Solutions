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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index,int inorderstart,int inorderend,int n,unordered_map<int,int> &m){
    if(index<0 || inorderstart>inorderend){
        return NULL;
    }

    int element = postorder[index--];
    TreeNode*  root = new TreeNode(element);
    int position = m[element];

    root->right = solve(inorder,postorder,index,position+1,inorderend,n,m);
    root->left = solve(inorder,postorder,index,inorderstart,position-1,n,m);
    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = postorder.size();
    int index = n-1;
    unordered_map<int,int> m;
    for(int i=0;i<inorder.size();i++){
        m[inorder[i]]=i;
    }
    return solve(inorder,postorder,index,0,n-1,n,m);
    }
};