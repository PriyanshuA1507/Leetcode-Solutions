class Solution {
public:
    // Check if the string `b` can be concatenated to `a` without having any common characters
    bool check(string& a, string& b) {
        unordered_set<char> charsInA(a.begin(), a.end());
        for (char ch : b) {
            if (charsInA.find(ch) != charsInA.end()) {
                return false;  // Found a common character
            }
        }
        return true;
    }

    // Check if the string contains all unique characters
    bool hasUniqueChars(const string& s) {
        unordered_set<char> charSet;
        for (char ch : s) {
            if (charSet.find(ch) != charSet.end()) {
                return false;  // Repeated character
            }
            charSet.insert(ch);
        }
        return true;
    }

    int solve(vector<string>& arr, int index, string current, int n) {
        if (index >= n) {
            return hasUniqueChars(current) ? current.size() : 0;
        }

        int take = 0;
        if (check(current, arr[index])) {
            take = solve(arr, index + 1, current + arr[index], n);
        }
        int nottake = solve(arr, index + 1, current, n);

        return max(take, nottake);
    }

    int maxLength(vector<string>& arr) {
        return solve(arr, 0, "", arr.size());
    }
};
