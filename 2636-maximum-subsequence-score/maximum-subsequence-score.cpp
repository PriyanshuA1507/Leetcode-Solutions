
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       
        vector<pair<int, int>> a;
        for (int i = 0; i < nums1.size(); i++) {
            a.push_back({nums2[i], nums1[i]});
        }
        long long ans =0;
        long long sum=0;
        sort(a.begin(), a.end());
        reverse(a.begin(),a.end());
       priority_queue<int,vector<int>,greater<int>> pq;
       for(int i=0;i<nums2.size();i++){
        sum+=a[i].second;
        pq.push(a[i].second);
         
        if(pq.size()>k){
        sum-=pq.top();
        pq.pop();
        }
        
        if(pq.size()==k){
            ans = max(ans, sum*a[i].first);
        }
        
       }
       return ans;
    }
};
