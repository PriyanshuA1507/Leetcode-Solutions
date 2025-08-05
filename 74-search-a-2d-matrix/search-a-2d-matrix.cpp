class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
             int r = m.size();
        int c = m[0].size();
        int start = 0;
        int end = r*c-1;
        while(start<=end){
        int mid = start + (end-start)/2;
        int element = m[mid/c][mid%c];
        if(element==target){
        return true;
        }
        else if(element>target){
        end  = mid-1;
        }
        else{
        start = mid+1;
        }
        }
        return false;   
    }
};