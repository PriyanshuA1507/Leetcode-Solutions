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
  int solve(TreeNode* root,int &cnt){
        if(root==NULL) return 1;

        int leftans=solve(root->left,cnt);
        int rightans=solve(root->right,cnt);

        if(leftans==0 || rightans==0){
            cnt++;
            return 2;
        }
        if(leftans==2 || rightans==2){
            return 1;
        }
        
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        int cnt=0;
        if(solve(root,cnt)==0){
            cnt++;
        }
        
        return cnt;
    }
};