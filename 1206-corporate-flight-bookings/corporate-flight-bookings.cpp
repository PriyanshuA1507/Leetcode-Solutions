class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      vector<int> ps(n,0);
      for(auto a:bookings){
        int f = a[0];
        int l = a[1];
        int seats = a[2];
        for(int i=f-1;i<l;i++){
         ps[i]+=seats;
        }
      }
      return ps;  
    }
};