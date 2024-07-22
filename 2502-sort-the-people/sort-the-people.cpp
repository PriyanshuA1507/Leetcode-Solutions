class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
         vector<string>v;
        unordered_map<int,string>mx;
        for(int i=0;i<heights.size();i++){
        mx[heights[i]]=names[i];
        }
        int ma=0;
        for(int i=0;i<heights.size();i++){
            ma=max(ma,heights[i]);
        }
        
        for(int j=ma;j>=1;j--){
       if(mx.count(j)>0){
           v.push_back(mx[j]);
       }
        }
        return v; 
    }
};