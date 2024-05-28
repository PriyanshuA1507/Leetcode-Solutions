class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
               int ans = 0;
        vector<int> a, b;

        for (int i = 0; i < s.size(); i++) {
            a.push_back(s[i] - '0');
        }

        for (int i = 0; i < t.size(); i++) {
            b.push_back(t[i] - '0');
        }

        vector<int> c(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            c[i] = abs(a[i] - b[i]);
        }

        int start = 0;
        int currentCost = 0;

        for (int end = 0; end < c.size(); end++) {
            currentCost += c[end];

            while (currentCost > maxCost) {
                currentCost -= c[start];
                start++;
            }

            ans = max(ans, end - start + 1);
        }

        return ans;

    }
};