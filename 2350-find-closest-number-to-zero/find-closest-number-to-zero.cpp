class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX; 
        int closestNumber = INT_MAX; 

        for (int num : nums) {
            int absNum = abs(num);
            if (absNum < ans || (absNum == ans && num > closestNumber)) {
                ans = absNum;
                closestNumber = num;
            }
        }

        return closestNumber;
    }
};