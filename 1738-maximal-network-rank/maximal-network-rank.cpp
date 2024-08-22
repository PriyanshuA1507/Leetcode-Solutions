class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> rank(n, 0);
        vector<vector<int>> adj(n, vector<int>(n, 0)); // Adjacency matrix

        for (auto& a : roads) {
            adj[a[0]][a[1]] = 1;
            adj[a[1]][a[0]] = 1;
            rank[a[0]]++;
            rank[a[1]]++;
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) { 
                    int currentRank = rank[i] + rank[j];
                    if (adj[i][j] == 1) { 
                        currentRank--; 
                    }
                    maxi = max(maxi, currentRank);
                }
            }
        }
        return maxi;
    }
};
