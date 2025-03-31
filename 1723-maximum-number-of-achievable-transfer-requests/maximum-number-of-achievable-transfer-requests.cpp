class Solution {
public:
   int m;
   int result = INT_MIN;
   void solve(int index,int count,int n,vector<int>& resultant,vector<vector<int>>& requests){
    if(index==m){
     int allzero = true;
     for(int &x:resultant){
    if(x!=0){
        allzero = false;
        break;
    }
     }
     if(allzero){
        result = max(result,count);
     }
     return;
    }
    int from = requests[index][0];
    int to = requests[index][1];
    resultant[from]--;
    resultant[to]++;
    solve(index+1,count+1,n,resultant,requests);
    resultant[from]++;
    resultant[to]--;
    solve(index+1,count,n,resultant,requests);
   }

    int maximumRequests(int n, vector<vector<int>>& requests) {
    m = requests.size();
    vector<int> resultant (n,0);
    solve(0,0,n,resultant,requests);
    return result;
    }
};