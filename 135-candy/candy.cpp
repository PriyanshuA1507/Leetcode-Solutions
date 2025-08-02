class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> lze(n,1);
        vector<int> rze(n,1);

        for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
        lze[i] = max(lze[i], lze[i-1]+1);
       }
        }

        for(int i = n-2;i>=0;i--){
        if(ratings[i] > ratings[i+1]){
        rze[i] = max(rze[i], rze[i+1]+1);
        }
        }

        int result = 0;
        for(int i=0;i<n;i++){
        result += max(lze[i],rze[i]);
        }
        return result;
    }
};