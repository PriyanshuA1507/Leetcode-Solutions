class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue<vector<double>> pq;
        for(auto i:classes)
        {
            double pass=i[0];
            double total=i[1];
            double avg=pass/total;
            double new_avg=(pass+1)/(total+1);
            pq.push({new_avg-avg,pass,total});
        }
        while(extraStudents--){
            auto tp=pq.top();
            
            pq.pop();
            double delta_avg=tp[0];
            double new_pass=tp[1]+1;
            double new_total=tp[2]+1;
            double avg=(new_pass)/(new_total);
            double new_avg = (new_pass+1)/(new_total+1);
            pq.push({new_avg-avg,new_pass,new_total});
        }
        double total_avg=0;
        while(!pq.empty())
        {
            double add_avg=(pq.top()[1])/pq.top()[2];
            
            total_avg+=add_avg;
            pq.pop();
        }
        return total_avg/classes.size();

    }
};