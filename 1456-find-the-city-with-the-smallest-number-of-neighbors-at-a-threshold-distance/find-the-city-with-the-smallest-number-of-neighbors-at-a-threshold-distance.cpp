class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<long long>> grid(n, vector<long long>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            grid[i][i] = 0;
        }

     
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            grid[u][v] = w;
            grid[v][u] = w;
        }

      
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][k] != INT_MAX && grid[k][j] != INT_MAX) {
                        grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                    }
                }
            }
        }

        
        vector<int> reachableCount(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] <= distanceThreshold) {
                    reachableCount[i]++;
                }
            }
        }

       
        int minReachable = INT_MAX;
        int city = -1;
        for (int i = 0; i < n; i++) {
            if (reachableCount[i] <= minReachable) {
                minReachable = reachableCount[i];
                city = i;
            }
        }

        return city;
    }
};
