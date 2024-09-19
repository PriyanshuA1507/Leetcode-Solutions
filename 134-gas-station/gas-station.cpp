class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int totalgas = 0, totalcost = 0;
       for(int i=0;i<gas.size();i++){
        totalgas+=gas[i];
        totalcost+=cost[i];
       }
       if(totalcost>totalgas){
        return -1;
       }
       int tankmaigas = 0, start=0;
       for(int i=0;i<gas.size();i++){
        tankmaigas+=gas[i];
        tankmaigas-=cost[i];
        if(tankmaigas<0){
            start = i+1;
            tankmaigas=0;}
       }
       return start;
    }
};