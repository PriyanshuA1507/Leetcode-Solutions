class Solution {
public:
    
    bool issimilar(string &s1, string &s2) {
        
        int n = s1.length();
        int diff = 0;
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i])
                diff++;
        }
        
        
        return diff == 2 || diff == 0;
    }
    void dfs(int node,unordered_map<int,vector<int>> adj,vector<bool>& vis){
        vis[node] = true;
        for(int a: adj[node]){
         if(!vis[a]){
         dfs(a,adj,vis);
         }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(issimilar(strs[i],strs[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        int count =0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
        if(!vis[i]){
        dfs(i,adj,vis);
        count++;
        }
        }
        return count;
        
    }
};