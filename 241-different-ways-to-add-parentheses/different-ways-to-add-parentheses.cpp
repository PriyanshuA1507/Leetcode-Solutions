class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        
        vector<int> result;
        for(int i=0;i<e.size();i++){
            if(e[i]=='-' || e[i]=='+' || e[i]=='*'){
            string a = e.substr(0,i);
          vector<int> left = diffWaysToCompute(a);
          string b = e.substr(i + 1);
          vector<int> right = diffWaysToCompute(b);

         for(auto a1:left){
        for(auto a2:right){
            if(e[i]=='+'){
                result.push_back(a1+a2);
            }
             if(e[i]=='-'){
                result.push_back(a1-a2);
            }
             if(e[i]=='*'){
                result.push_back(a1*a2);
            }
        }
        }
        }
        }
        if(result.size()==0){
            result.push_back(stoi(e)); 
            return result;
        }
      return result;
    }
};