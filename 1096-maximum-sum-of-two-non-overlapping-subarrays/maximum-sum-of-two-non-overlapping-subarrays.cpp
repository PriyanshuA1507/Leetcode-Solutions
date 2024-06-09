class Solution {
public:
    int ans(vector<int>& nums, int fl ,int sl){
    int n = nums.size();
        int a = fl; 
        vector<int> fs; 
        int b = sl; 
        int i = 0;
        int j = 0;
        int sum = 0;
        while (j < n) {
            sum += nums[j];
            if ((j - i + 1) < a) {
                j++;
            } else {
                fs.push_back(sum);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        int start = 0;
        int end = 0;
        int c = 0;
        int ans = INT_MIN;
        int sum1 = 0;
        for(int c=0;c<fs.size();c++){
        end = a;
        start=a;
        sum1 =0;
        while (end < n) {
            sum1 += nums[end];
            end++;
            if (end - start == b) {
                ans = max(ans, fs[c] + sum1);
                sum1 -= nums[start];
                start++;
            }
        }
        a++;
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
       return max(ans(nums,fl,sl),ans(nums,sl,fl));
    }
};
