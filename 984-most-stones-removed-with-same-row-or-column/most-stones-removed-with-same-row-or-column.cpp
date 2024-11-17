class Solution {
public:
    int findparent(int x, vector<int>& parent) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findparent(parent[x], parent);
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int a_parent = findparent(a, parent);
        int b_parent = findparent(b, parent);

        if (a_parent != b_parent) {
    
            if (rank[a_parent] > rank[b_parent]) {
                parent[b_parent] = a_parent;
            } else if (rank[a_parent] < rank[b_parent]) {
                parent[a_parent] = b_parent;
            } else {
                parent[b_parent] = a_parent;
                rank[a_parent]++;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0, maxcol = 0;
        for (auto& a : stones) {
            maxrow = max(maxrow, a[0]);
            maxcol = max(maxcol, a[1]);
        }

        int offset = maxrow + 1; 
        int maxnode = maxrow + maxcol + 2;

        vector<int> parent(maxnode);
        vector<int> rank(maxnode, 0);
        for (int i = 0; i < maxnode; i++) {
            parent[i] = i;
        }

        unordered_map<int, int> m; 


        for (auto& stone : stones) {
            int noderow = stone[0];
            int nodecol = stone[1] + offset; 
            Union(noderow, nodecol, parent, rank);
            m[noderow] = 1; 
            m[nodecol] = 1; 
        }

        int cnt = 0;
      
        for (auto& a : m) {
            if (findparent(a.first, parent) == a.first) {
                cnt++;
            }
        }

        
        return stones.size() - cnt;
    }
};
