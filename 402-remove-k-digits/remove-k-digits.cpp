class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.size();i++){
         while(s.size()!=0 && s.top()>num[i] && k>0){
            k--;
            s.pop();
         }
         s.push(num[i]);
        }

        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        string ans = "";
        while(s.size()!=0){
         ans.push_back(s.top());
         s.pop();
        }
        reverse(ans.begin(), ans.end());

         while (!ans.empty() && ans[0] == '0') {
            ans.erase(ans.begin());
        }

         return ans.empty() ? "0" : ans;
    }
};