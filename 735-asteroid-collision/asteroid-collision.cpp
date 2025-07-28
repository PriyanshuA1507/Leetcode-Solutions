class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){
        bool burst = false;
        while(st.size()!=0 && st.top()>0 && arr[i]<0){
         if(st.top() == -arr[i]){
            st.pop();
         }
         else if(st.top() < -arr[i]){
          st.pop();
          continue;
         }
         burst = true;
         break;
        }
        if(!burst){
        st.push(arr[i]);
        }
        }
      
       while(st.size()!=0){
        ans.push_back(st.top());
        st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};