class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
    vector<int> ans;
       for(int i=0;i<=nums.size()-k;i++){
        bool a= true;
        for(int j=i;j<i+k-1;j++){
            if(nums[j]+1!=nums[j+1]){
                a = false;
                break;
            }
            if(nums[j]>=nums[j+1]){
                a = false;
                break;
            }
        }
        if(a){
            ans.push_back(nums[i+k-1]);
        }
        else{
            ans.push_back(-1);
        }
       }
       return ans;
    }
};