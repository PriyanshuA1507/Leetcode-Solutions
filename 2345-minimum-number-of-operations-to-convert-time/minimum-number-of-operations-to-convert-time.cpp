class Solution {
public:
    int convertTime(string current, string correct) {
        if(current == correct) {
            return 0;
        }
        int ans = 0;

        
        int currentHours = (current[0] - '0') * 10 + (current[1] - '0');
        int currentMinutes = (current[3] - '0') * 10 + (current[4] - '0');
        int correctHours = (correct[0] - '0') * 10 + (correct[1] - '0');
        int correctMinutes = (correct[3] - '0') * 10 + (correct[4] - '0');

     
        int currentTotalMinutes = currentHours * 60 + currentMinutes;
        int correctTotalMinutes = correctHours * 60 + correctMinutes;

        int diff = correctTotalMinutes - currentTotalMinutes;

        
        ans += diff / 60;  
        diff %= 60;
        ans += diff / 15;  
        diff %= 15;
        ans += diff / 5;   
        diff %= 5;
        ans += diff;       

        return ans;
    }
};