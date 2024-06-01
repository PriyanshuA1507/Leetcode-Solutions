class Solution {
public:
    int scoreOfString(string s) {
       int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            
            int num1 = s[i] - '0';   
            int num2 = s[i + 1] - '0'; 
            ans += std::abs(num2 - num1); 
        }
        return ans;
        
    }
};