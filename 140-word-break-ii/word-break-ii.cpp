class Solution {
public:
  
    bool wordExists(string &word, const unordered_set<string> &wordDict) {
        return wordDict.find(word) != wordDict.end();
    }

    void solverec(const string &s, unordered_set<string> &wordDict, string current, vector<string> &ans) {
        if (s.empty()) {
            ans.push_back(current.substr(1)); 
            return;
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (wordExists(prefix, wordDict)) {
                solverec(s.substr(i), wordDict, current + " " + prefix, ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> ans;
        solverec(s, wordSet, "", ans);
        return ans;
    }
};
