class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int ans = arr[0];  
        int sum = arr[0];

        vector<int> ls(n), rs(n);

    
        ls[0] = sum;
        for (int i = 1; i < n; i++) {
            sum = max(arr[i], sum + arr[i]); 
            ans = max(sum, ans);
            ls[i] = sum;
        }

        
        sum = arr[n - 1];
        rs[n - 1] = sum;
        for (int i = n - 2; i >= 0; i--) {
            sum = max(arr[i], sum + arr[i]);  
            ans = max(sum, ans);
            rs[i] = sum;
        }

       
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, ls[i - 1] + rs[i + 1]);  
        }

        return ans;
    }
};
