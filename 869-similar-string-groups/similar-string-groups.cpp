class Solution {
public:
    vector<int> par, size;

    int findpar(int u) {
        return par[u] == u ? u : (par[u] = findpar(par[u]));
    }

    bool issimilar(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i] && ++count > 2) {
                return false;
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        par.resize(n); // Use resize to set the size of the vector
        for (int i = 0; i < n; i++) {
            par[i] = i; // Initialize each element to its own set
        }
        int noofset = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (issimilar(strs[i], strs[j])) {
                    int p1 = findpar(i);
                    int p2 = findpar(j);
                    if (p1 != p2) {
                        par[p1] = p2; // Merge the sets
                        noofset--;
                    }
                }
            }
        }
        return noofset;
    }
};
