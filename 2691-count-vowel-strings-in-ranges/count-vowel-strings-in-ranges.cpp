class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ps(n, 0);

        // Declare the lambda correctly using auto
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (int i = 0; i < n; i++) {
            string a = words[i];
            char s = a[0];
            char e = a[a.size() - 1];
            int val = isVowel(s) && isVowel(e) ? 1 : 0;
            ps[i] = (i > 0 ? ps[i - 1] : 0) + val;
        }

        vector<int> ans;
        for (auto a : queries) {
            int l = a[0];
            int r = a[1];
            ans.push_back(ps[r] - (l > 0 ? ps[l - 1] : 0));
        }

        return ans;
    }
};
