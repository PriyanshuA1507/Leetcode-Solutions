class Solution {
public:
    int solve(vector<int>& nums, int si, int ei) {
        if (si > ei) {
            return 0;
        }
        
        
            int scoreStart = nums[si] + min(solve(nums, si + 2, ei),solve(nums,si+1,ei-1));
            int scoreEnd = nums[ei] + min(solve(nums, si+1, ei - 1),solve(nums,si,ei-2));
            return max(scoreStart, scoreEnd);
    }

    bool predictTheWinner(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int player1Score = solve(nums, 0, nums.size() - 1);
        return player1Score >= (totalSum - player1Score);
    }
};
