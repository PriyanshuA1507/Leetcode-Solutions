class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;  // Accept $5 bill
            } 
            else if (bills[i] == 10) {
                if (five <= 0) {  // Need one $5 to give change
                    return false;
                }
                five--;  // Give one $5 as change
                ten++;  // Accept $10 bill
            } 
            else if (bills[i] == 20) {
                if (ten > 0 && five > 0) {  // Prioritize giving one $10 and one $5 as change
                    ten--;
                    five--;
                } 
                else if (five >= 3) {  // If no $10 is available, give three $5 bills as change
                    five -= 3;
                } 
                else {
                    return false;  // Not enough change available
                }
            }
        }
        return true;  // Successfully provided change for all customers
    }
};