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
class CBTInserter {
public:
    queue<TreeNode*> q; 
    TreeNode* root1;     

    CBTInserter(TreeNode* root) {
        root1 = root;

        queue<TreeNode*> tempQueue;
        tempQueue.push(root);

        while (!tempQueue.empty()) {
            TreeNode* current = tempQueue.front();
            tempQueue.pop();

            
            if (!current->left || !current->right) {
                q.push(current);
            }

            if (current->left) tempQueue.push(current->left);
            if (current->right) tempQueue.push(current->right);
        }
    }

    int insert(int val) {
        TreeNode* node = new TreeNode(val);

       
        TreeNode* parent = q.front();

        if (!parent->left) {
            parent->left = node;
        } else if (!parent->right) {
            parent->right = node;
            q.pop();  
        }

        q.push(node);

        return parent->val;  
    }

    TreeNode* get_root() {
        return root1;
    }
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */