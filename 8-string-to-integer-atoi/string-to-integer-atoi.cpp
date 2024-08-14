class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool n = false;
        vector<char> a;
        bool started = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && !started) {
                continue;  // Skip leading spaces
            }
            if (s[i] == '-' && !started) {
                n = true;  // Detect negative sign
                started = true;
                continue;
            }
            if (s[i] == '+' && !started) {
                started = true;  // Detect positive sign
                continue;
            }
            if (isdigit(s[i])) {
                a.push_back(s[i]);  // Collect digits
                started = true;
            } else {
                break;  // Stop if a non-digit character is found
            }
        }

        int size = a.size();
        for (int i = 0; i < size; i++) {
            ans = ans * 10 + (a[i] - '0');  // Calculate the number
            if (ans > INT_MAX) {  // Handle overflow
                return n ? INT_MIN : INT_MAX;
            }
        }

        return n ? -ans : ans;
    }
};
