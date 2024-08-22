class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> adj;
        vector<int> rank(n,0);
        for(auto& a:roads){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
            rank[a[0]]++;
            rank[a[1]]++;
        }
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
          for(int j=0;j<n && j!=i;j++){
         int rank1 = rank[i] + rank[j];
         if (find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    rank1--; 
                }
        maxi = max(maxi, rank1);
          }
        }
        return maxi;
        
    }
};