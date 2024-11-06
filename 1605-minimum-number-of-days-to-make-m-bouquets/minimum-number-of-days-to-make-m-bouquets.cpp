class Solution {
public:
    bool check(int mid,vector<int>& bloomDay, int m, int k){
    int bouquets = 0;
        int flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                flowers++;
                if (flowers == k) { 
                    bouquets++;
                    flowers = 0; 
                }
            } else {
                flowers = 0; 
            }
        }
        
        return bouquets >= m;  
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()){
            return -1;
        }
        int start = 1;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(start<=end){
            int mid = (start) + (end-start)/2;
            if(check(mid,bloomDay,m,k)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};