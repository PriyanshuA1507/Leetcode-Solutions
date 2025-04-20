class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
     int n = cp.size();
     int maxi = -1e8;
     int lsum = 0 ,rsum = 0;
     for(int i=0;i<k;i++){
        lsum+= cp[i];
     }   
     int ri = n-1;
    maxi = max(maxi,lsum);
    for(int i = k-1;i>=0;i--){
     lsum -= cp[i];
     rsum += cp[ri];
     ri -= 1;
     maxi = max(maxi,lsum+rsum);
    }
    return maxi;
    }
};