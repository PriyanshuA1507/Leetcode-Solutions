class Solution {
public:
    int minimumDeletions(string s) {
        int b1 = 0;
        int a1 = 0;
        vector<int> a,b;
       for(int i=0;i<s.size();i++){
         if(s[i]=='b'){
            b.push_back(b1);
            b1++;
         }
         else{
            b.push_back(b1);
         }
       }
       for(int i=s.size()-1;i>=0;i--){
         if(s[i]=='a'){
            a.push_back(a1);
            a1++;
         }
         else{
            a.push_back(a1);
         }
       }
       reverse(a.begin(), a.end());
        
        int minDeletions = INT_MAX;
        
        for (int i = 0; i < s.size(); i++) {
            minDeletions = min(minDeletions, a[i] + b[i]);
        }
        
        return minDeletions;

    }
};