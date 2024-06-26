class Solution {
public:
    long long minimalKSum(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        long long f = 1;
        long long ans =0;
        for(int i=0;i<nums.size();i++){
            if(k==0){
                break;
            }
            if(nums[i]-f>0){
           long long count = min(k,nums[i]-f);
           k-=count;
          long long a = f + count - 1; 
          long long b = f;  
          ans += (a * (a + 1) / 2) - ((b - 1) * b / 2);

            }
            f= nums[i]+1;
        }
        if(k>0){
        while(k>0){
            ans+=f;
            f++;
            k--;
        }
        }
        return ans;
        
    }
};