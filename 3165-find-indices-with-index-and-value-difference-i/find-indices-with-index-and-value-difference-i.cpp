class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> ans;
        bool a =true;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(abs(j-i)>=indexDifference && abs(nums[i]-nums[j])>=valueDifference){
                    ans.push_back(i);
                    ans.push_back(j);
                    a = false;
                    break;
                }
            }
            if(!a){
                break;
            }
        }
        if(ans.size()==0){
            ans.push_back(-1);
             ans.push_back(-1);
        }
        return ans;
    }
};