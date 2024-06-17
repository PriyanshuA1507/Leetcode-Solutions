class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool a,b;
       sort(s1.begin(),s1.end());
       sort(s2.begin(),s2.end());
       for(int i=0;i<s1.size();i++){
        if(s1[i]>=s2[i]){
            a = true;
        }
        else{
            a = false;
            break;
        }
       }
       for(int i=0;i<s1.size();i++){
        if(s2[i]>=s1[i]){
            b = true;
        }
        else{
            b = false;
            break;
        }
       }
       return (a||b);
    }
};