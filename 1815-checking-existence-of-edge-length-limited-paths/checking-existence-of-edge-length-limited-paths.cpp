class Solution {
public:
    int findparent(int x,vector<int>& parent){
        if(x==parent[x]){
            return x;
        }
    return findparent(parent[x],parent);
    }
    void union1(int x,int y, vector<int>& parent,vector<int>& rank){
        int x_parent = findparent(x,parent);
        int y_parent = findparent(y,parent);
        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[y_parent] = x_parent;
           rank[x_parent]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> parent(n);
        vector<int> rank(n,0);
        vector<bool> result(queries.size());
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        auto lambda = [&](vector<int>& a, vector<int>&b){
            return a[2]< b[2];
        };
        sort(queries.begin(),queries.end(), lambda);
        sort(edgeList.begin(),edgeList.end(), lambda);
        int j = 0;
        for(auto a: queries){
         int u = a[0];
         int v = a[1];
         int t = a[2];
         int idx = a[3];

         while(j<edgeList.size() && edgeList[j][2]<t){
            union1(edgeList[j][0],edgeList[j][1],parent,rank);
            j++;
         }
         result[idx]= findparent(u,parent)==findparent(v,parent);
        }
        return result;
    }
};