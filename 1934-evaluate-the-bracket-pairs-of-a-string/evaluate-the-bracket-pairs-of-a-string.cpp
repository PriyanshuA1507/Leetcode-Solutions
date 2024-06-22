class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string, string> m;
        for (int i = 0; i < k.size(); i++) {
            m[k[i][0]] = k[i][1];
        }

        string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                i++;
                string key;
                while (i < s.size() && s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }
                if (m.find(key) != m.end()) {
                    result += m[key];
                } else {
                    result += '?';
                }
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};