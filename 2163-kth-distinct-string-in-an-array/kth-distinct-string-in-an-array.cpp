class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
          unordered_map<string,int> m;
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]]>0){
                m[arr[i]]+=1;
            }
            else m[arr[i]]=1;
        }
       string s;
    int j=1;
    for(int i=0;i<arr.size();i++){
        if(m[arr[i]]==1){
            if(j==k){
                s=arr[i];
                break;
            }else{
                j++;
            }
        }
    }
      
      return s; 
    }
};