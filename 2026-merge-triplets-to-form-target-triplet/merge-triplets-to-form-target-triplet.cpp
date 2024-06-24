class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    int a = target[0];
    int b = target[1];
    int c = target[2];
    bool a1= false;
    bool b1 = false;
    bool c1 = false;
    for(int i=0;i<triplets.size();i++){
        if(triplets[i][0]==a && triplets[i][1]<=b && triplets[i][2]<=c){
            a1 = true;
        }
        if(triplets[i][1]==b && triplets[i][0]<=a && triplets[i][2]<=c ){
            b1 = true;
        }
        if(triplets[i][2]==c && triplets[i][0]<=a && triplets[i][1]<=b ){
            c1 = true;
        }
    }
    return (a1&&b1&&c1);
        
    }
};