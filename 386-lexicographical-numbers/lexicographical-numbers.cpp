class Solution {
public:
    vector<int> lexicalOrder(int n) {
      vector<string> a;
      vector<int> result;
      for(int i=1;i<=n;i++){
        a.push_back(to_string(i));
      }
      sort(a.begin(),a.end());
      for(int i=0;i<a.size();i++){
        result.push_back(stoi(a[i]));
      }
      return result;
    }
};