class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      std::vector<int> a;
        int64_t xxroy = 0; 
        for (int val : nums) {
            xxroy = xxroy ^ val;
        }

        
        int64_t rbsm = xxroy & -xxroy; 
        int x = 0;
        int y = 0;
        for (int val : nums) {
            if ((val & rbsm) == 0) {
                x = x ^ val;
            } else {
                y = y ^ val;
            }
        }

        if (x < y) {
            a.push_back(x);
            a.push_back(y);
        } else {
            a.push_back(y);
            a.push_back(x);
        }

        return a;
    }
};