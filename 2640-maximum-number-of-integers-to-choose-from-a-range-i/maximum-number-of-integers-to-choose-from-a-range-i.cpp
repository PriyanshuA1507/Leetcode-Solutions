class Solution {
public:
   
    int maxCount(vector<int>& banned, int n, int maxSum) {
       unordered_map<int,int> m;
        for(int i=0;i<banned.size();i++){
            m[banned[i]]++;
        }
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++){
    
        if(m[i]==0 && sum+i<=maxSum){
            ans++;
            sum+=i;
        }
        }
        return ans;   
    }
};