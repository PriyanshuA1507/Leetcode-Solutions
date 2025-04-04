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
    TreeNode* findLCA(TreeNode* root1, TreeNode* root2, TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        if(root1==root || root2==root)
            return root;
        TreeNode* left = findLCA(root1, root2, root->left);
        TreeNode* right = findLCA(root1, root2, root->right);
        if(left==nullptr)
            return right;
        else if(right==nullptr)
            return left;
        else
            return root;
    }
    TreeNode* flcaofleaves(vector<TreeNode*> nodes, TreeNode* root) {
        if(nodes.size()==1)
            return nodes[0];
        TreeNode* lca = nodes[0];
        for(int i=1;i<nodes.size();i++) {
            lca = findLCA(lca, nodes[i], root);
        }
        return lca;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> deepleaves;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            int s=q.size();
            if(deepleaves.size()>0)
                deepleaves.clear();
            for(int i=0;i<s;i++){
                TreeNode* a= q.front();
                q.pop();
                deepleaves.push_back(a);
                if(a->left){
                    q.push(a->left);
                }
                if(a->right){
                    q.push(a->right);
                }
            }
        }
        TreeNode* answer = flcaofleaves(deepleaves,root);
        return answer;
    }
};