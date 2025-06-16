class Solution {
public:
    int candy(vector<int>& ratings) {
    long long n = ratings.size();
    vector<long long> r(n,1);
     vector<long long> l(n,1);
      long long ans = 0;

    for(long long i=1;i<n;i++){
     if(ratings[i]>ratings[i-1]){
        r[i] = r[i-1]+1;
     }
    }
   
   for(long long i=n-2;i>=0;i--){
    if(ratings[i]>ratings[i+1]){
     l[i] = l[i+1]+1;
    }
   }


for(long long i=0;i<n;i++){
ans+=max(l[i],r[i]);
}
return ans;

    }
};