class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        
        // Finding the level of the label in the binary tree
        int level = 0;
        int copyLabel = label;
        while (copyLabel > 0) {
            copyLabel /= 2;
            level++;
        }
        
        while (level > 0) {
            result.push_back(label);
            int maxNum = (1 << level) - 1;
            int minNum = 1 << (level - 1);
            label = (maxNum + minNum - label) / 2;
            level--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

