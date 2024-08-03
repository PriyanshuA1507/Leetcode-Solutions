class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
          sort(target.begin(),target.end());
       bool a=true;
        sort(arr.begin(),arr.end());
        if(target.size()!=arr.size()){
            a=false;
        } 
       for(int i=0;i<target.size();i++){
           if(target[i]!=arr[i]){
            a=false;
            break;
           }
       }
       return a;
    }
};