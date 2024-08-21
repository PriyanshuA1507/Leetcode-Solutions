class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto & a:edges){
            adj[a[0]].push_back(a[1]);
            indegree[a[1]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                result.push_back(i);
            }
        }
     sort(result.begin(),result.end());
     return result;
    }
};