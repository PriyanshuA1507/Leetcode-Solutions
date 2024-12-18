class Solution {
public:
   void solve(int num,int n,int k, vector<int>& result){
    if(n==0){
      result.push_back(num);
      return;
    }
    int lastdigit = num%10;
    if(lastdigit+k<=9 ){
      solve(num*10+ (lastdigit+k),n-1,k,result);
    }
    if(k!=0 && lastdigit-k>=0){
      solve(num*10+ (lastdigit-k),n-1,k,result);
    }
   }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
       for(int i=1;i<=9;i++){
        solve(i,n-1,k,result);
       }
       return result;
    }
};