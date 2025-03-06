class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        for(int i = 0; i < a.size(); i++) {
            bool destroyed = false;
            
            // Process collisions while there are asteroids in the stack and the current asteroid is negative
            while (!st.empty() && a[i] < 0 && st.top() > 0) {
                if (st.top() < -a[i]) {  
                    // Top asteroid is smaller, so destroy it
                    st.pop();
                    continue;  // Check again with the next top element
                } 
                else if (st.top() == -a[i]) {  
                    // Both asteroids are equal, destroy both
                    st.pop();
                }
                
                // If top asteroid is larger, the current asteroid is destroyed
                destroyed = true;
                break;
            }
            
            // If not destroyed, push to stack
            if (!destroyed) {
                st.push(a[i]);
            }
        }
        
        // Convert stack to result vector
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
