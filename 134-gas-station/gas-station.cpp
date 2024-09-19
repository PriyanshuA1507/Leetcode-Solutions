class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
              int total_gas=0,total_cost=0;
        for(int i=0;i<gas.size();i++)
        {
            total_gas+=gas[i];
            total_cost+=cost[i];
        }
        if(total_gas<total_cost)
            return -1;
        int start=0;
        int tank_me_gas=0;
        for(int i=0;i<gas.size();i++)
        {
            tank_me_gas+=gas[i];
            tank_me_gas-=cost[i];
            
            if(tank_me_gas<0)
            {
                start=i+1;
                tank_me_gas=0;
            }  
        }
        return start;   
    }
};