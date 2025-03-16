class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int maxJump = 0;

        // Check jumps by moving forward skipping one stone at a time
        for (int i = 2; i < n; i += 2) {
            maxJump = max(maxJump, stones[i] - stones[i - 2]);
        }

        // Check jumps by moving backward skipping one stone at a time
        for (int i = 3; i < n; i += 2) {
            maxJump = max(maxJump, stones[i] - stones[i - 2]);
        }

        // Edge case: Compare the jump from the last to second last stone
        maxJump = max(maxJump, stones[n - 1] - stones[n - 2]);

        return maxJump;
    }
};
