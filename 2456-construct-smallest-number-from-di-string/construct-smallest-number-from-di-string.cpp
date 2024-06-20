class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> s;
        string result;

        for(int i=0;i<=pattern.size();i++){
            s.push(i+1);
            if(pattern[i]=='I' || i==pattern.size()){
                while(!s.empty()){
                    result+=to_string(s.top());
                    s.pop();
                }
            }
        }
        return result;
    }
};