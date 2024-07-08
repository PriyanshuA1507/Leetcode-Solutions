class Solution {
public:
    string reorganizeString(string s) {
          map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        
        string a = "";
        priority_queue<pair<int, char>> pq;
        for (auto& pair : m) {
            pq.push({pair.second, pair.first}); 
        }
        
        pair<int, char> prev = {-1, '#'}; 
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            a += curr.second;
            
            if (prev.first > 0) {
                pq.push(prev);
            }
            
            curr.first--;
            prev = curr;
        }
        
        if (a.size() != s.size()) {
            return "";
        }
        
        return a; 
    }
};