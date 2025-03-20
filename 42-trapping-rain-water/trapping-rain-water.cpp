class Solution {
public:
    int trap(vector<int>& height) {
    int ans = 0;
    int n = height.size();
     int left = 0, right = n-1;
     int leftmax = -1e8, rightmax = -1e8;
    while(left<=right){
      if(height[left]<=height[right]){
       if(height[left]>leftmax){
        leftmax = height[left];
       }
       else{
       ans += leftmax-height[left];
       }
       left++;
      }
      else{
        if(height[right]>rightmax){
        rightmax = height[right];
       }
       else{
       ans += rightmax-height[right];
       }
      right--;
      }
     }
     return ans;
    }
};