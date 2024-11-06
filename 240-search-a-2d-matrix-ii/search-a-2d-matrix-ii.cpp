class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
   int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;  // Found the target
            } 
            if (matrix[row][col] > target) {
                col--;  // Move left
            } else {
                row++;  // Move down
            }
        }
        
        return false;  // Target not found
    }
};