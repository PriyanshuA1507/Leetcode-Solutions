class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        string ans = "";
        priority_queue<pair<char, int>> pq;
        unordered_map<char, int> m;
        for (auto a : s) {
            m[a]++;
        }
        for (auto a : m) {
            pq.push({a.first, a.second});
        }

        while (!pq.empty()) {
            auto a = pq.top();
            pq.pop();

            if (a.second > rl) {
                int b = rl;
                while (b-- > 0) {
                    ans.push_back(a.first);
                }
                
                if (a.second-rl>0) {
                    if(pq.empty()){
                        break;
                    }
                    auto c = pq.top();
                    pq.pop();

                    ans.push_back(c.first); 
                    c.second--;

                    if (c.second > 0) {
                        pq.push({c.first, c.second});
                    }
                }

                pq.push({a.first, a.second - rl}); 
            } 
            else { 
                
                while (a.second-- > 0) {
                    ans.push_back(a.first);
                }
            }
        }

        return ans;
    }
};
