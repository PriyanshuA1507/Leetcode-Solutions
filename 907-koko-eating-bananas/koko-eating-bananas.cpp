class Solution {
public: 
    bool isPossible(vector<int>& piles, int speed, int h) {
        long long hoursNeeded = 0; 
        for (int pile : piles) {
            hoursNeeded += (pile - 1) / speed + 1; 
        }
        return hoursNeeded <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isPossible(piles, mid, h)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;  
    }
};
