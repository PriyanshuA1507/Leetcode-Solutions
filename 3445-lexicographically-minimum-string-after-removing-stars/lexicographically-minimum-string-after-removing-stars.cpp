class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        string ans;
        unordered_map<int,int> m1;
         auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; 
            }
            return a.first > b.first; 
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(comp)>pq(comp);
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
            pq.push({s[i],i});
            }
            else{     
         m1[pq.top().second]++;
         pq.pop();
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='*' && m1[i]==0){
            ans.push_back(s[i]);
        }
     }
     return ans;
    }
};