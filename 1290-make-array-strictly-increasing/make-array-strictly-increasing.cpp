class Solution {
public:
      map<pair<int, int>, int> mp;
    int solve(vector<int>& arr1, vector<int>& arr2, int index,int prev){
        if(index>=arr1.size()){
            return 0;
        }
          if(mp.find({index, prev}) != mp.end())
            return mp[{index, prev}];

        int option1 = 1e9;
        if(arr1[index]>prev){
          option1 = solve(arr1,arr2,index+1,arr1[index]);
        }
          int option2 = 1e9+1;
        auto it = upper_bound(begin(arr2), end(arr2), prev);
        
        if(it != end(arr2)) {
            int i = it - begin(arr2);
            option2 = 1 + solve(arr1, arr2,index+1, arr2[i]);
        }
        return mp[{index, prev}] = min(option1,option2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
     sort(arr2.begin(),arr2.end());
      mp.clear();
     int ans= solve(arr1,arr2,0,INT_MIN);
     if(ans==1e9){
        return -1;
     }
     return ans;
    }
};