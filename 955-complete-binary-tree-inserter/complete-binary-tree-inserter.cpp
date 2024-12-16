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
    queue<TreeNode*> q;  // Stores nodes that are not fully populated
    TreeNode* root1;     // Root of the tree

    CBTInserter(TreeNode* root) {
        root1 = root;

        // Level-order traversal to initialize the queue with incomplete nodes
        queue<TreeNode*> tempQueue;
        tempQueue.push(root);

        while (!tempQueue.empty()) {
            TreeNode* current = tempQueue.front();
            tempQueue.pop();

            // Add current node to the queue if it is not fully populated
            if (!current->left || !current->right) {
                q.push(current);
            }

            // Push children to the temporary queue for further traversal
            if (current->left) tempQueue.push(current->left);
            if (current->right) tempQueue.push(current->right);
        }
    }

    int insert(int val) {
        TreeNode* node = new TreeNode(val);

        // The front of the queue is the first incomplete node
        TreeNode* parent = q.front();

        // Attach the new node to the first available child slot
        if (!parent->left) {
            parent->left = node;
        } else if (!parent->right) {
            parent->right = node;
            q.pop();  // Remove the node when both children are filled
        }

        // Add the new node to the queue as it may need children in the future
        q.push(node);

        return parent->val;  // Return the value of the parent node
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