class Solution {
public:
    int solve(vector<int>& stonevalue, int index, vector<int>& memo) {
        if (index >= stonevalue.size()) {
            return 0;
        }
        if (memo[index] != INT_MIN) {
            return memo[index];
        }
        int result = INT_MIN;
        result = max(result, stonevalue[index] - solve(stonevalue,index+1,memo));
        if(index+1<stonevalue.size()){
        result = max(result,stonevalue[index]+stonevalue[index+1]-solve(stonevalue,index+2,memo));
        }
        if(index+2<stonevalue.size()){
        result = max(result,stonevalue[index]+stonevalue[index+1]+  stonevalue[index+2]-solve(stonevalue,index+3,memo));
        }
        memo[index] = result;
        return memo[index];
    }

    string stoneGameIII(vector<int>& stoneValue) {
       int n = stoneValue.size();
        vector<int> memo(n, INT_MIN); 
       int a = solve(stoneValue,0,memo);
       if(a>0){
        return "Alice";
       }
       if(a<0){
        return "Bob";
       }
       return "Tie";
    }
};
