class Solution {
public:
    int partitionString(string s) {
        
       int ans = 1; 
        unordered_map<char, int> m;
        
        for (char c : s) {
            if (m[c] > 0) { 
                ans++; 
                m.clear();
            }
            m[c] = 1; 
        }
        
        return ans;
    }
};