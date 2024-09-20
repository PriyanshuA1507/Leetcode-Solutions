class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for (int a : tasks) {
            m[a]++;
        }

       
        for (auto& [task, count] : m) {
            if (count < 2) {
                return -1;  
            }

           
            ans += count / 3;  
            if (count % 3 != 0) {
                ans++;  
            }
        }

        return ans;
    }
};
