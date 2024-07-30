class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        vector<int> last_occurrence(26, -1); 
        vector<bool> visited(26, false);
        
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i] - 'a'] = i; 
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i] - 'a']) continue; 
            
            while (!ans.empty() && ans.back() > s[i] && last_occurrence[ans.back() - 'a'] > i) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }
        
        return ans;
    }
};