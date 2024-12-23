class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int fr = 0, fc = 0, lr = m - 1, lc = n - 1;
        
        while (fr <= lr && fc <= lc) {
            // Traverse from left to right along the top row
            for (int i = fc; i <= lc; i++) {
                ans.push_back(matrix[fr][i]);
            }
            fr++; // Move the top boundary down
            
            // Traverse from top to bottom along the last column
            for (int i = fr; i <= lr; i++) {
                ans.push_back(matrix[i][lc]);
            }
            lc--; // Move the right boundary left
            
            // Check if there is a bottom row to traverse
            if (fr <= lr) {
                for (int i = lc; i >= fc; i--) {
                    ans.push_back(matrix[lr][i]);
                }
                lr--; // Move the bottom boundary up
            }
            
            // Check if there is a left column to traverse
            if (fc <= lc) {
                for (int i = lr; i >= fr; i--) {
                    ans.push_back(matrix[i][fc]);
                }
                fc++; // Move the left boundary right
            }
        }
        
        return ans;
    }
};
