class Solution {
public:
    int halveArray(vector<int>& nums) {
      int operations = 0;
        priority_queue<double> pq;
        double totalSum = 0;
        
        // Initialize the priority queue and calculate the total sum
        for (int num : nums) {
            pq.push(num);
            totalSum += num;
        }
        
        double target = totalSum / 2;
        double currentSum = totalSum;
        
        // Reduce the sum until it is less than or equal to half of the original sum
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