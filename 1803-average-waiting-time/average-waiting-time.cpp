class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        double a = 0;
        int time = c[0][0];
        for(int i=0;i<c.size();i++){
            if(time>=c[i][0]){
            time+=c[i][1];}
            if(time<c[i][0]){
              time = c[i][0];
              time+=c[i][1];
            }
            
            a+=(time-c[i][0]);
        }
        return (double)a/n;
        
    }
};