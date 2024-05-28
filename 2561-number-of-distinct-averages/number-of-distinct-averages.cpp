class Solution {
public:
    int distinctAverages(vector<int>& nums) {
       unordered_set<double> a;
        sort(nums.begin(),nums.end());
        int start=0;
        int end = nums.size()-1;
        while(start<end){
           double x= (1.0)*((double)(nums[start])+(double)(nums[end]))/2;
            a.insert(x);
            start++;
            end--;
        }
        return a.size();
    }
};