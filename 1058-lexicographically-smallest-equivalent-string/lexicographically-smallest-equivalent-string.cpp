class Solution {
public:
    int findparent(char c, vector<int>& parent) {
        if (c == parent[c]) {
            return c;
        }
        return parent[c] = findparent(parent[c], parent);  // Path compression
    }
    
    void unionfind(char a, char b, vector<int>& parent, vector<int>& rank) {
        char parent_a = findparent(a, parent);
        char parent_b = findparent(b, parent);
        
        if (parent_a != parent_b) {
            if (parent_a < parent_b) {
                parent[parent_b] = parent_a;
            } else if (parent_a > parent_b) {
                parent[parent_a] = parent_b;
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        vector<int> rank(26, 1);
        
        // Initialize parent of each character to itself
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        
        // Apply union-find on the characters in s1 and s2
        for (int i = 0; i < s1.size(); i++) {
            unionfind(s1[i] - 'a', s2[i] - 'a', parent, rank);
        }
        
        // Build the smallest equivalent string
        string result = baseStr;
        for (int i = 0; i < baseStr.size(); i++) {
            result[i] = findparent(baseStr[i] - 'a', parent) + 'a';
        }
        
        return result;
    }
};
