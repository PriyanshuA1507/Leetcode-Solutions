class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> node;  // hd -> lvl -> nodes
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if (!root) return ans;

        // BFS traversal with hd and lvl tracking
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            node[hd][lvl].push_back(frontNode->val);

            if (frontNode->left)
                q.push({frontNode->left, {hd - 1, lvl + 1}});
            if (frontNode->right)
                q.push({frontNode->right, {hd + 1, lvl + 1}});
        }

        // Build the final answer
        for (auto i : node) {
            vector<int> col;
            for (auto j : i.second) {
                vector<int> temp = j.second;
                sort(temp.begin(), temp.end());  // Sort same-level nodes
                col.insert(col.end(), temp.begin(), temp.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
