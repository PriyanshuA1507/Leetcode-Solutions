class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int num =0;
        int i = n-1;
        int count =0;
        while(i>0){
            if(s[i]=='1'){
             if(num==0){
                count+=2;
                num++;
             }
             else{
                count++;
             }
            }
            else{
                count++;
                if(num==1){
                    count++;
                }
            }
            i--;
        }
        if(num==1){
            count++;
        }
        return count;
    }
};