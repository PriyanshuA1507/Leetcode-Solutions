class Solution {
public:
    int minimumChairs(string s) {
        int l=0;
        int chair=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E'){
                if(l==0){
                    chair++;
                }
                else{
                    l--;
                }
            }
            else{
                l++;
            }
        }
     return chair;
    }
};