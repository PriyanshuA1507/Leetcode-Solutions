class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;  

        vector<int> ra(n, 1); 

       
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                ra[i] = ra[i - 1] + 1;
            }
        }

     
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                ra[i] = max(ra[i], ra[i + 1] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += ra[i];
        }

        return ans;
    }
};
