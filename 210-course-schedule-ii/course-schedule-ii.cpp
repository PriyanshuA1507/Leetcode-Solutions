class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        queue<int> q;
        int c=0;
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto a: prerequisites){
        int u = a[0], v = a[1];
        adj[u].push_back(v);
        indegree[v]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                c++;
            }
        }
        while(q.size()!=0){
        int a = q.front();
        result.push_back(a);
        q.pop();
        for(auto v: adj[a]){
         indegree[v]--;
         if(indegree[v]==0){
        c++;
         q.push(v);
         }
        }
        }
        reverse(result.begin(),result.end());
        if(c==numCourses){
        return result;
        }
        return {};
    }
};