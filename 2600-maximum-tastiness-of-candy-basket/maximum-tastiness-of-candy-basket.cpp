class Solution {
public:
    bool ispossible(vector<int>& price, int k,int mid){
        int cc =1;
        int lastpos = price[0];
        for(int i=0;i<price.size();i++){
            if(price[i]-lastpos>=mid){
                cc++;
                if(cc==k){
                    return true;
                }
                lastpos = price[i];
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int s = 1;
        int maxi = -1;
        for(int i=0;i<price.size();i++){
            maxi = max(maxi,price[i]);
        }
        int e = maxi;
        int ans =0;
        int mid = e + (e-s)/2;
        while(s<=e){
            if(ispossible(price,k,mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};