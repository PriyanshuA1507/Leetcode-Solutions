class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int ans=0;
        for(int i=0;i<b.size();i++){
            if(b[i]>0){
             int j = i+1;
             while(j<b.size()){
                b[j]= max(0,b[j]-1);
                j++;
             }
             ans++;
            }
        }
        return ans;
    }
};