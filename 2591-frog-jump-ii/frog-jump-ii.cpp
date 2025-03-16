class Solution {
public:
    bool check(vector<int>& stones,int mid){
    for(int i=2;i<stones.size();i+=2){
    if(stones[i]-stones[i-2]>mid){
     return false;
    }
    }
    for(int i=3;i<stones.size();i+=2){
    if(stones[i]-stones[i-2]>mid){
     return false;
    }
    }
    return true;
    }
    int maxJump(vector<int>& stones) {
    if(stones.size()==2){
        return stones[1]-stones[0];
    }
     int start = 1;
     int ans = 0;
     int end = *max_element(stones.begin(),stones.end());
     while(start<=end){
    int mid = start + (end-start)/2;
    if(check(stones,mid)){
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