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
    unordered_map<int,int>m;
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int& index,int inorderstart,int inorderend,int n){
    if(index>=n || inorderstart>inorderend){
        return NULL;
    }
    int element = preorder[index++];
    TreeNode* root = new TreeNode(element);
    int position = m[element];
    root->left = solve(inorder,preorder,index,inorderstart,position-1,n);
    root->right = solve(inorder,preorder,index,position+1,inorderend,n);
    return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
       int preorderindex = 0;
       for(int i=0;i<inorder.size();i++){
        m[inorder[i]] = i;
       }
       TreeNode* ans = solve(inorder,preorder,preorderindex,0,n-1,n);
       return ans; 
    }
};