class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;
        stack<int> s;
        
        for(int i = 0; i < a.size(); i++) {
            bool destroyed = false;
            while(!s.empty() && a[i] < 0 && s.top() > 0) {
                if(s.top() < -a[i]) {
                    s.pop(); // The top positive asteroid is destroyed
                } else if(s.top() == -a[i]) {
                    s.pop(); // Both are destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // The current negative asteroid is destroyed
                    break;
                }
            }
            if(!destroyed) {
                s.push(a[i]);
            }
        }

        // Collect the remaining asteroids in the correct order
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
