class Solution {
public:
    int sumSubtree(TreeNode* node, unordered_map<int, int>& sum_count) {
        if (node == nullptr) {
            return 0;
        }
        int sum = node->val + sumSubtree(node->left, sum_count) + sumSubtree(node->right, sum_count);
        sum_count[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sum_count;
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        sumSubtree(root, sum_count);

        int max_freq = 0;
        for (const auto& entry : sum_count) {
            if (entry.second > max_freq) {
                max_freq = entry.second;
            }
        }

        for (const auto& entry : sum_count) {
            if (entry.second == max_freq) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};