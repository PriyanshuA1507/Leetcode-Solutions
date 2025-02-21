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
class FindElements {
public:
set<int> num;
   void traverse(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left){
            root->left->val = root->val*2+1;
            num.insert(2 * root->val + 1);
            traverse(root->left);
        }
        if(root->right){
            root->right->val = root->val*2+2;
             num.insert(2 * root->val + 2);
            traverse(root->right);
        }  
   }
    FindElements(TreeNode* root) {
    root->val=0;
    num.insert(0);
    traverse(root);
    }
    
    bool find(int target) {
      if(num.find(target) != num.end()) {
            return true;
        }
        return false;  
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */