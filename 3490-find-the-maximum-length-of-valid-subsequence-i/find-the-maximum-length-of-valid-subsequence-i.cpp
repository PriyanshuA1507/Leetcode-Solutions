class Solution {
public:
    int count1(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                ans++;
            }
        }
        return ans;
    }

    int count2(vector<int>& nums) {
        int ans = 0;
        bool o = true;
        bool e = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0 && o) {
                ans++;
                o = false;
                e = true;
            } else if (nums[i] % 2 == 0 && e) {
                ans++;
                e = false;
                o = true;
            }
        }
        return ans;
    }

    int count3(vector<int>& nums) {
        int ans = 0;
        bool e = true;
        bool o = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0 && o) {
                ans++;
                o = false;
                e = true;
            } else if (nums[i] % 2 == 0 && e) {
                ans++;
                e = false;
                o = true;
            }
        }
        return ans;
    }

    int count4(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }

    int maximumLength(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        
       int ans = max({count1(nums),count2(nums),count3(nums),count4(nums)});
        
        return ans ; 
    }
};
