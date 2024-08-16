class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN;
        
        int min1_index = -1, max1_index = -1;
        
      
        for (int i = 0; i < n; i++) {
            int first = arrays[i][0];
            int last = arrays[i].back();
            
            if (first < min1) {
                min2 = min1;
                min1 = first;
                min1_index = i;
            } else if (first < min2) {
                min2 = first;
            }
            
            if (last > max1) {
                max2 = max1;
                max1 = last;
                max1_index = i;
            } else if (last > max2) {
                max2 = last;
            }
        }
        
     
        if (min1_index != max1_index) {
            return max1 - min1;
        }
        
        
        return max(max1 - min2, max2 - min1);
    }
};
