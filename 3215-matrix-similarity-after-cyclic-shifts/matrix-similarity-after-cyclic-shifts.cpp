class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        // Normalize k to avoid extra rotations
        k %= m;

        vector<vector<int>> rotated = mat;

        for (int i = 0; i < n; ++i) {
            vector<int>& row = mat[i];
            vector<int> newRow(m);

            if (i % 2 == 0) {
                // Shift right
                for (int j = 0; j < m; ++j) {
                    newRow[(j + k) % m] = row[j];
                }
            } else {
                // Shift left
                for (int j = 0; j < m; ++j) {
                    newRow[(j - k + m) % m] = row[j];
                }
            }

            rotated[i] = newRow;
        }

        return rotated == mat;
    }
};
