class Solution {
public:
    int round(double a,double b){
        int x=a/b;
        double n=a/b;
        if(n-x>0)
            return x+1;
        return x;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
     int s = 1;
     int e = 0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]>e){
            e = nums[i];
        }
     }
     int ans =0;
     int mid = e + (e-s)/2;
     while(s<=e){
         int sum=0;
            for(int i=0;i<nums.size();++i){
                sum+= (round(nums[i],mid));
            }

        if(sum<=threshold){
            ans = mid;
            e = mid-1;
        }
        else{
          s = mid+1;}
          mid = s+(e-s)/2;   
     }
     return mid;
    }
};