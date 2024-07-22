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
   int findposition(vector<int> in,int element,int n){
    for(int i=0;i<n;i++){
     if(in[i]==element)
     return i;
    }
     return -1;
   }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int &index,int inorderstart,int inorderend,int n){
     if(index>=n || inorderstart>inorderend){
        return NULL;
     }
     int element=preorder[index++];
     TreeNode* root = new TreeNode(element);
     int position = findposition(inorder,element,n);
     root->left = solve(inorder,preorder,index,inorderstart,position-1,n);
     root->right = solve(inorder,preorder,index,position+1,inorderend,n);

     return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preorderindex = 0;
        TreeNode* ans = solve(inorder,preorder,preorderindex,0,n-1,n);
        return ans;
    }
};