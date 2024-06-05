class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
     vector<int> ans;

     
        for (int i = 0; i < s.size(); i++) {
            int row = startPos[0];
            int col = startPos[1];
            int steps = 0;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == 'R') {
                    col++;
                } else if (s[j] == 'L') {
                    col--;
                } else if (s[j] == 'U') {
                    row--;
                } else if (s[j] == 'D') {
                    row++;
                }

                if (row >= 0 && row < n && col >= 0 && col < n) {
                    steps++;
                } else {
                    break;
                }
            }
            ans.push_back(steps);
        }
        return ans; 
    }
};