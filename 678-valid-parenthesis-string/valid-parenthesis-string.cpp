class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // minimum possible open parentheses
        int maxOpen = 0; // maximum possible open parentheses

        for (char ch : s) {
            if (ch == '(') {
                minOpen++;
                maxOpen++;
            } else if (ch == ')') {
                minOpen--;
                maxOpen--;
            } else { // ch == '*'
                minOpen--; // '*' can be treated as ')'
                maxOpen++; // '*' can be treated as '('
            }

            if (maxOpen < 0) {
                return false; // More closing brackets than opening
            }

            if (minOpen < 0) {
                minOpen = 0; // Reset minOpen to 0 because it can't be negative
            }
        }

        return minOpen == 0; // Ensure all open parentheses are closed
    }
};
