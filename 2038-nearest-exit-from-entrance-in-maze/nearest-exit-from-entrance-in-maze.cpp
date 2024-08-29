class Solution {
public:
    const vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Fixed directions
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = true;
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            ans++;
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for (auto& a : dir) {
                    int r = p.first + a[0];
                    int c = p.second + a[1];
                    if (r >= 0 && c >= 0 && r < n && c < m && maze[r][c] == '.' && !vis[r][c]) {
                        if (r == 0 || c == 0 || r == n - 1 || c == m - 1) {
                            return ans; 
                        }
                        vis[r][c] = true;
                        q.push({r, c});
                    }
                }
            }
        }

        return -1; 
    }
};
