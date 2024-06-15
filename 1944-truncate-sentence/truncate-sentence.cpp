class Solution {
public:
    string truncateSentence(string s, int k) {
         string a;
        int i = 0;
        int spaces = 0; 
        while (i < s.length() && spaces < k) {
             if (s[i] == ' ') {
                spaces++; 
            }
            if(spaces>=k){
                break;
            }
            a.push_back(s[i]);
            i++;
        }
        return a;
    }
};