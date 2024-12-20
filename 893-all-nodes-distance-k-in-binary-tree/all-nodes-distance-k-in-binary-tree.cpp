class Solution {
public:
    void buildgraph(TreeNode* root, unordered_map<int, vector<int>>& adj) { 
        if (!root) {
            return;
        }
        if (root->left) {
            adj[root->val].emplace_back(root->left->val);
            adj[root->left->val].emplace_back(root->val);
            buildgraph(root->left, adj);
        }
        if (root->right) {
            adj[root->val].emplace_back(root->right->val);
            adj[root->right->val].emplace_back(root->val);
            buildgraph(root->right, adj);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        buildgraph(root, adj); 
        queue<int> q;
        unordered_map<int, bool> visited;
        visited[target->val] = true;
        q.push(target->val);
        int level = 0;
        vector<int> ans;
        
        while (!q.empty()) {
            int a = q.size();
            if (level == k) {
                while (!q.empty()) {
                    ans.push_back(q.front());
                    q.pop();
                }
                break; 
            }
            for (int i = 0; i < a; i++) {
                int b = q.front();
                q.pop();
                for (int n : adj[b]) {
                    if (!visited[n]) {
                        q.push(n);
                        visited[n] = true;
                    }
                }
            }
            level++;
        }
        return ans;
    }
};
