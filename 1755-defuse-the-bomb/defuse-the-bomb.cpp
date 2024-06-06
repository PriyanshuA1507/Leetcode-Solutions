class Solution {
public:
    vector<int> decrypt(vector<int>& c, int k) {
       int n = c.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans; 
        } else if (k > 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= k; ++j) {
                    ans[i] += c[(i + j) % n];
                }
            }
        } else {
            k = -k; 
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= k; ++j) {
                    ans[i] += c[(i - j + n) % n];
                }
            }
        }
        
        return ans;
    }
};