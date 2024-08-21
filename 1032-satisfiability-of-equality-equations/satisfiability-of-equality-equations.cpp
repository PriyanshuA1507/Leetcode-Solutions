class Solution {
public:
    vector<int> parent, rank;

    int findparent(int x, vector<int>& parent) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findparent(parent[x], parent); // Path compression
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = findparent(x, parent);
        int y_parent = findparent(y, parent);
        
        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent] += 1;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        
        // Process equations with '=='
        for (auto& a : equations) {
            if (a[1] == '=') {
                Union(a[0] - 'a', a[3] - 'a', parent, rank);
            }
        }
        
        // Check equations with '!='
        for (auto& a : equations) {
            if (a[1] == '!') {
                int parent_first = findparent(a[0] - 'a', parent);
                int parent_second = findparent(a[3] - 'a', parent);
                if (parent_first == parent_second) {
                    return false;
                }
            }
        }
        return true;
    }
};