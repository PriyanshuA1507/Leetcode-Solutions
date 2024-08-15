class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int n = image.size(), m = image[0].size();
        int originalColor = image[sr][sc];
        
        if (originalColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            
            for (int i = 0; i < dir.size(); i++) {
                int r = a.first + dir[i][0];
                int c = a.second + dir[i][1];

                if (r >= 0 && c >= 0 && r < n && c < m && image[r][c] == originalColor) {
                    image[r][c] = color;
                    q.push({r, c});
                }
            }
        }

        return image;
    }
};
