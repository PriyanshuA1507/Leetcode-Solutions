class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = -1;
        vector<int> inorder(n,0);
        unordered_map<int,vector<int>> adj;
        for(auto a: edges){
        int u = a[0];
        int v = a[1];
         adj[u].push_back(v);
         inorder[v]++;
        }
        for(int i=0;i<n;i++){
        if(inorder[i]==0 && ans == -1){
            ans = i;
        }
        else if(inorder[i]==0 && ans != -1){
            return -1;
        }
        }
       return ans;
    }
};