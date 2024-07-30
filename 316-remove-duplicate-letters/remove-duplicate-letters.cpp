class Solution {
public:
    string removeDuplicateLetters(string s) {
        string s1 ="";
        vector<int> last_occurrence(26, -1); 
        vector<bool> visited(26, false);
        
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i] - 'a'] = i; 
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i] - 'a']) continue; 
            
            while (!s1.empty() && s1.back() > s[i] && last_occurrence[s1.back() - 'a'] > i) {
                visited[s1.back() - 'a'] = false;
                s1.pop_back();
            }
            
            s1.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }
        
        return s1;
    }
};