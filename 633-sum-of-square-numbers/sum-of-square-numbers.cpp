class Solution {
public:
    bool judgeSquareSum(int c) {
       
        long long start = 0;
        long long end = sqrt(c);  
        
        while (start <= end) {
            long long sum = start * start + end * end;
            
            if (sum == c) {
                return true;
            }
            else if (sum > c) {
                end--;  
            }
            else {
                start++;  
            }
        }
        
        return false;
    }
};
