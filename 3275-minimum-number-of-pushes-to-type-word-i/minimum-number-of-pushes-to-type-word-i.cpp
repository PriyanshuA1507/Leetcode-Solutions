class Solution {
public:
  Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumPushes(string word) {
        int n = word.size();
       if(n<=8){
        return n;
       }
       if(n>8 && n<=16){
        return 8 + ((n-8)*2);
       }
        if(n>16 && n<=24){
        return 24+ ((n-16)*3);
       }
       
        return 48 + ((n-24)*4);
    }
};