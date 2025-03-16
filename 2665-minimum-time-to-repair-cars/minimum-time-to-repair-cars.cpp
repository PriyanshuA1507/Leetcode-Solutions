class Solution {
public:
    bool check(vector<int>& ranks,int cars,long long mt){
     long long totalCars = 0;
        for(int i = 0; i < ranks.size(); i++){
            totalCars += (long long)sqrt(mt / ranks[i]);  
            if(totalCars >= cars) return true; 
        }
        return totalCars >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans = 0;
        sort(ranks.begin(),ranks.end());
        long long start = 0;
        long long end = 1e14;
        while(start<=end){
        long long mid = start + (end-start)/2;
        if(check(ranks,cars,mid)){
         ans = mid;
        end = mid-1;
        }
        else{
        start = mid+1;
        }
        }
        return ans; 
    }
};