class Solution {
public:

    int minFlips(string target) {
        int n = target.size();
        char a = '0';
        int flip =0;
        for(int i=0;i<n;i++){
            if(target[i]!=a){
                flip++;
                if(a=='0')a='1';
                else if(a=='1')a='0';
            }
        }
        return flip;    
    }
};