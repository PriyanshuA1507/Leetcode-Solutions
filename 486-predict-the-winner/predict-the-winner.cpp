class Solution {
public:
    int solve(vector<int>& nums, int si, int ei, int turn) {
        if (si > ei) {
            return 0;
        }
        
        if (turn == 1) {

            int scoreStart = nums[si] + solve(nums, si + 1, ei, 0);
            int scoreEnd = nums[ei] + solve(nums, si, ei - 1, 0);
            return max(scoreStart, scoreEnd);
        } else {
            int scoreStart = solve(nums, si + 1, ei, 1);
            int scoreEnd = solve(nums, si, ei - 1, 1);
            return min(scoreStart, scoreEnd);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int player1Score = solve(nums, 0, nums.size() - 1, 1);
        return player1Score >= (totalSum - player1Score);
    }
};
