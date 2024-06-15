
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       
        vector<pair<int, int>> a;
        for (int i = 0; i < nums1.size(); i++) {
            a.push_back({nums2[i], nums1[i]});
        }
        sort(a.begin(), a.end(), greater<>());

       
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, ans = 0;

        
        for (int i = 0; i < a.size(); i++) {
            minHeap.push(a[i].second);
            sum += a[i].second;

           
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                ans = max(ans, sum * a[i].first);
            }
        }

        return ans;
    }
};
