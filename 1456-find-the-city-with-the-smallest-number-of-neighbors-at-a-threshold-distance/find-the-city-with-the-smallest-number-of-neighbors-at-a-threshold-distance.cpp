class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> grid(n, vector<long long>(n,INT_MAX));
        for(int i=0;i<n;i++){
            grid[i][i] = 0;
        }
        for(auto a:edges){
        int u = a[0];
        int v = a[1];
        int w = a[2];
        grid[u][v] = w;
        grid[v][u] = w;
        }
        for(int via = 0; via<n;via++){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
        }
        }
        }
     vector<int> viscount(n,0);
     for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    if(i!=j && grid[i][j]<=distanceThreshold){
       viscount[i]++; 
    }
    }
     }
     
     int minCount = INT_MAX;
        int city = -1;
        for (int i = 0; i < n; i++) {
            if (viscount[i] < minCount || (viscount[i] == minCount && i > city)) {
                minCount = viscount[i];
                city = i;
            }
        }

        return city;
    }
};