class Solution {
public:
    bool check(int mid, vector<int>& piles, int h) {
        long long ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] + mid - 1) / mid;  
        }
        return ans <= h;  
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ma = *max_element(piles.begin(), piles.end());
        int start = 1;
        int end = ma;
        int ans = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check(mid, piles, h)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};
