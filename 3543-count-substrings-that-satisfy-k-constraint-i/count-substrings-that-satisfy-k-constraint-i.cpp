class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int count = 0;
        
       
        for (int i = 0; i < n; i++) {
            int zeroCount = 0, oneCount = 0;
            
            for (int j = i; j < n; j++) {
                if (s[j] == '0') {
                    zeroCount++;
                } else {
                    oneCount++;
                }
                
                
                if (zeroCount <= k || oneCount <= k) {
                    count++;
                } else {
                  
                    break;
                }
            }
        }
        
        return count;
    }
};
