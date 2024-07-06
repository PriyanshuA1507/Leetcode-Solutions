class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total_chalk = 0;
        for (int c : chalk) {
            total_chalk += c;
        }

        k %= total_chalk;
       for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return -1; 
    }
};