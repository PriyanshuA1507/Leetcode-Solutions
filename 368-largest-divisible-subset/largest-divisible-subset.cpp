class Solution {
public:
    int dp[1001];
    void solverec(vector<int>&ans,vector<int>&temp,vector<int>& nums,int idx){
        if(idx>=nums.size()){
            if(temp.size()>ans.size()){
                ans=temp;
            }
            return;
        }
        solverec(ans,temp,nums,idx+1);
        if(temp.size()==0){
            temp.push_back(nums[idx]);
            solverec(ans,temp,nums,idx+1);
            temp.pop_back();
        }else{
            if(((int)temp.size()>dp[idx])&&nums[idx]%temp.back()==0){
                dp[idx]=temp.size();
                temp.push_back(nums[idx]);
                solverec(ans,temp,nums,idx+1);
                temp.pop_back();
            }
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>temp;
        memset(dp,-1,sizeof(dp));
        solverec(ans,temp,nums,0);
        return ans;
    }
};