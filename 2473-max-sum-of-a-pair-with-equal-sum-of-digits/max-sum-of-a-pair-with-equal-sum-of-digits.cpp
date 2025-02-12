class Solution {
public:
    int sumd(int n)
    {
        int ans=0;
        while(n>0)
        {
            ans+=n%10;
            n/=10;

        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
          
          sort(nums.begin(),nums.end());
          unordered_map<int,int>m;
          int ans=-1;
          for(int i=0;i<nums.size();i++)
          {
           
              if(m.find(sumd(nums[i]))!=m.end())
              {
                  ans=max(ans,nums[i]+m[sumd(nums[i])]);
                  m.erase(sumd(nums[i]));

              }
              m[sumd(nums[i])]=nums[i];
          }
          return ans;

    }
};
