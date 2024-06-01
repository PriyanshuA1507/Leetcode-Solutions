class Solution {
public:
    int halveArray(vector<int>& nums) {
      int operations = 0;
        priority_queue<double> pq;
        double totalSum = 0;
        
        
        for (int num : nums) {
            pq.push(num);
            totalSum += num;
        }
        
        double target = totalSum / 2;
        double currentSum = totalSum;
        
       
        while (currentSum > target) {
            double maxElement = pq.top();
            pq.pop();
            currentSum -= maxElement / 2;
            pq.push(maxElement / 2);
            operations++;
        }
        
        return operations;
    }
};