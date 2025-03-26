class Solution {
public:
    bool check(string &s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int solve(string &s, int index) {
        if (index >= s.size()) {
            return 0;
        }

        int count = 0;
        for (int i = index; i < s.size(); i++) {
            if (check(s, index, i)) {
                count++; // Count this palindrome
            }
        }
        return count + solve(s, index + 1); // Move to the next starting index
    }

    int countSubstrings(string s) {
        return solve(s, 0);
    }
};
