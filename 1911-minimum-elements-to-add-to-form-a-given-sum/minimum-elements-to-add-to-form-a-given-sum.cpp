class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long diff = abs(goal-sum);
       return ceil((double)diff/(double)(limit));

    }
};