class Solution {
public:
    int minimumRecolors(string b, int k) {
        int start=0;
        int end = 0;
        int ans = INT_MAX;
        int mini =0; 
        int c = 0;
        while(end<b.size()){
        if (b[end] == 'W') {
                mini++;
            }
            c++;
            end++;
        if(c==k){
            ans = min(mini,ans);
            if(b[start]=='W'){
                mini--;
            }
            start++;
            c--;
         }
        }
       return ans;                       

    }
};