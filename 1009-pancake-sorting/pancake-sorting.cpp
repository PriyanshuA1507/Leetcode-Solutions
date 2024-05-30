class Solution {
public:
    int findMaxIndex(vector<int>& arr, int l) {
        int maxi = INT_MIN;
        int id = -1;
        for (int i = 0; i <= l; i++) {
            if (maxi < arr[i]) {
                maxi = arr[i];
                id = i;
            }
        }
        return id;
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for (int l = arr.size() - 1; l >= 1; l--) {
            int mi = findMaxIndex(arr, l);
            if (mi != l) {
                reverse(arr.begin(), arr.begin() + mi + 1); 
                ans.push_back(mi + 1);
                reverse(arr.begin(), arr.begin() + l + 1);
                ans.push_back(l + 1);
            }
        }
        return ans;
    }
};
