class Solution {
public:
    string clearDigits(string s) {
        string a="";
        for(int i=s.size()-1;i>=1;i--){
            bool found = false;
            if(isdigit(s[i]) ){
            for(int j = i-1;j>=0;j--){
                if(isalpha(s[j]) && !found){
                    s[i]='@';
                    s[j]='@';
                    found = true;
                }
            }
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='@'){
            a.push_back(s[i]);}
        }
        return a;
    }
};