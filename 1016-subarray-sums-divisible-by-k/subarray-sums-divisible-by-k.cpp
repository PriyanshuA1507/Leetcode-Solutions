class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int ans = 0;
        int sum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;

        for (int num : nums) {
            sum = (sum + num) % k;
            if (sum < 0) {
                sum += k; 
            }
            ans += prefixSumCount[sum];
            prefixSumCount[sum]++;
        }

        return ans;
    }
};
//We need to return the number of subarray that is divisible by a given number k.
//The logic used here is that when the remainder of 2 subarray array is same then the leftover element of the larger subarray would be divisible by k.
//For negative remainder if thre is we add k to neuralize. (-2%5 is -2) ((-2+5)%5 is 3)