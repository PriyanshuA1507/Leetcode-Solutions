class Solution {
public:
    vector<int> diStringMatch(string pattern) {
         stack<int> s;
        vector<int> result;

        for(int i=0;i<=pattern.size();i++){
            s.push(i);
            if(pattern[i]=='I' || i==pattern.size()){
                while(!s.empty()){
                    result.push_back(s.top());
                    s.pop();
                }
            }
        }
        return result;
    }
};