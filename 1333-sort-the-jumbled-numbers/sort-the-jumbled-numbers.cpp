class Solution {
public:
    void call(int a, unordered_map<int, int>& n, unordered_map<int, int> m) {
        string a1 = to_string(a);
        for (int i = 0; i < a1.size(); i++) {
            int c = a1[i] - '0';
            a1[i] = m[c] + '0'; 
        }
        int b = stoi(a1);
        n[a] = b;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> m, n;
        for (int i = 0; i < mapping.size(); i++) {
            m[i] = mapping[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            call(nums[i], n, m);
        }
        
       sort(nums.begin(), nums.end(), [&n](int a, int b) {
            return n[a] < n[b];
        });
        
        return nums;
    }
};