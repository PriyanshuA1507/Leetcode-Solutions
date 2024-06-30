class Dsu {
public:
    vector<int> size, parent;
    Dsu(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }
    int uparent(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = uparent(parent[u]);
    }
    void unionbysize(int a, int b) {
        int pa = uparent(a);
        int pb = uparent(b);
        if (pa == pb) {
            return;
        }
        if (size[pa] > size[pb]) {
            parent[pb] = pa;
            size[pa] += size[pb];
        } else {
            parent[pa] = pb;
            size[pb] += size[pa];
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> type3;
        vector<pair<int,int>> type2;
        vector<pair<int,int>> type1;

        for (auto i : edges) {
            if (i[0] == 1) {
                type1.push_back({i[1], i[2]});
            }
            if (i[0] == 2) {
                type2.push_back({i[1], i[2]});
            }
            if (i[0] == 3) {
                type3.push_back({i[1], i[2]});
            }
        }

        Dsu a(n), b(n);
        int edge = 0;

        for (auto i : type3) {
            int x = i.first;
            int y = i.second;
            bool yes = false;
            if (a.uparent(x) != a.uparent(y)) {
                a.unionbysize(x, y);
                yes = true;
            }
            if (b.uparent(x) != b.uparent(y)) {
                b.unionbysize(x, y);
                yes = true;
            }
            if (yes) {
                edge++;
            }
        }

        for (auto i : type2) {
            int x = i.first;
            int y = i.second;
            if (b.uparent(x) != b.uparent(y)) {
                b.unionbysize(x, y);
                edge++;
            }
        }

        for (auto i : type1) {
            int x = i.first;
            int y = i.second;
            if (a.uparent(x) != a.uparent(y)) {
                a.unionbysize(x, y);
                edge++;
            }
        }

        int alice = *max_element(a.size.begin(), a.size.end());
        int bob = *max_element(b.size.begin(), b.size.end());

        if (alice != n || bob != n) {
            return -1;
        }

        return edges.size() - edge;
    }
};