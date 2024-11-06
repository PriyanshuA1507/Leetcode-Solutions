class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> b;
        double ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int a:nums1){
            pq.push(a);
        } 
        for(int a:nums2){
            pq.push(a);
        } 
        while(pq.size()!=0){
            int a = pq.top();
            pq.pop();
            b.push_back(a);
        }
          int mid = b.size()/2;
        if(b.size()%2==0){
        ans = (b[mid-1]+b[mid])/2;
        }
        else{
        ans = (b[mid]);
        }
        return ans;
    }
};