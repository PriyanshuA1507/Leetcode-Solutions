class Solution {
public:
   
    vector<vector<int>> memo;
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }


    int minCuts(const string &s, int start, int end) {
      
        if (start >= end || isPalindrome(s, start, end)) {
            return 0;
        }

        if (memo[start][end] != -1) {
            return memo[start][end];
        }

        int min_cut = end - start; 

        for (int k = start; k < end; k++) {
            if (isPalindrome(s, start, k)) {
                min_cut = min(min_cut, 1 + minCuts(s, k + 1, end));
            }
        }

        return memo[start][end] = min_cut;
    }

    int minCut(string s) {
        int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return minCuts(s, 0, n - 1);
    }
};
