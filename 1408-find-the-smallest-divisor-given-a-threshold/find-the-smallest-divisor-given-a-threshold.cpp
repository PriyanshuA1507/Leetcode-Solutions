class Solution {
public:
      bool possible(vector<int>& nums, int threshold,int mid){
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0){
                ans+=(nums[i]/mid);
            }
            else{
                ans+=(nums[i]/mid +1);
            }
        }
        if(ans<=threshold){
            return true;
        }
        return false;
      }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(nums, threshold, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};