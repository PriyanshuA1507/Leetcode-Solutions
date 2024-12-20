class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes; // To store nodes by horizontal and level order
        queue<pair<TreeNode*, pair<int, int>>> q; // Queue for BFS traversal
        
        q.push(make_pair(root, make_pair(0, 0))); // Push root with horizontal distance and level
        
        while (!q.empty()) {
            auto temp = q.front(); 
            q.pop(); // Pop the front element
            
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first; // Horizontal distance
            int lvl = temp.second.second; // Level
            
            nodes[hd][lvl].push_back(frontNode->val); // Insert into map
            
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1))); // Push left child
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1))); // Push right child
            }
        }
        
        vector<vector<int>> ans; // Final answer
        
        for (auto& p : nodes) {
            vector<int> col; // To store values in one vertical line
            for (auto& q : p.second) {
                sort(q.second.begin(), q.second.end()); // Sort values at the same level
                col.insert(col.end(), q.second.begin(), q.second.end()); // Merge into column
            }
            ans.push_back(col); // Add column to result
        }
        
        return ans;
    }
};
