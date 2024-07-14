class Solution {
public:
    string getSmallestString(string s) {
        bool a = false;
        for(int i=0;i<s.size()-1;i++){
            if(!a && s[i]>s[i+1] && ((s[i]%2==0 && s[i+1]%2==0)||(s[i]%2!=0 && s[i+1]%2!=0))){
                swap(s[i],s[i+1]);
                a= true;
            }
        }
        return s;    
    }
};