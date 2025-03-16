class Solution {
public:
    bool check(int n, vector<int>& q,int mid){
        int ans = 0;
        for(auto a:q){
         ans+=(a + mid - 1) / mid;
        }
        return ans<=n;
        }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1;
        int end = 1e8;
        int ans =0;
        while(start<=end){
        int mid = start + (end-start)/2;
        if(check(n,quantities,mid)){
        ans = mid;
        end = mid-1;
        }
        else{
            start = mid+1;
        }
        }
        return ans;
    }
};