class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int s1 = 0;
        int start=0;
    for (int i = 0; i < s.size() && s1 < g.size(); i++) {
            if (s[i] >= g[s1]) {
                s1++;
                start++;
            }
        }

    return start;
    }
};