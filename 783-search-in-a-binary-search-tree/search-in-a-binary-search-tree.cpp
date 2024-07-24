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
    TreeNode* searchBST(TreeNode* root, int x) {
        TreeNode* temp=root;
        TreeNode* ans;
        while(temp!=NULL){
            if(temp->val==x){
                ans = temp;
                break;
            }
            if(temp->val>x){
                temp=temp->left;
            }
            else{
            temp = temp->right;
            }
        }
        return ans;
    }
};