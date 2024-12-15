class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr; 

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int a = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < a; i++) {
                Node* b = q.front();
                q.pop();

                if (prev) {
                    prev->next = b;
                }
                prev = b;

                if (b->left) q.push(b->left);
                if (b->right) q.push(b->right);
            }

        
            if (prev) {
                prev->next = nullptr;
            }
        }

        return root;
    }
};
