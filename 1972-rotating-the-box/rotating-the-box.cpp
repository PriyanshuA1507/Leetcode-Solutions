class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();

        // Create the rotated matrix with swapped dimensions
        vector<vector<char>> ans(col, vector<char>(row, '.'));

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[j][row - i - 1] = box[i][j];
            }
        }

        // Simulate gravity in the rotated box
        for (int col = 0; col < ans[0].size(); col++) {
            int emptyRow = ans.size() - 1; 
            for (int row = ans.size() - 1; row >= 0; row--) {
                if (ans[row][col] == '#') {
                    // Move stone to the lowest available position
                    ans[row][col] = '.';
                    ans[emptyRow][col] = '#';
                    emptyRow--;
                } else if (ans[row][col] == '*') {
                    // Reset the emptyRow to just above the obstacle
                    emptyRow = row - 1;
                }
            }
        }

        return ans;
    }
};
