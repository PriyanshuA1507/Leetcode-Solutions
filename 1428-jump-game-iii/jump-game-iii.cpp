class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
          vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(q.size()!=0){
        int a = q.size();
        for(int i=0;i<a;i++){
         int b = q.front();
         q.pop();
         if(arr[b]==0){
            return true;
         }
         if(b+arr[b]<arr.size() && !visited[b+arr[b]]){
            q.push(b+arr[b]);
            visited[b+arr[b]] = true;
         }
         if(b-arr[b]>=0 && !visited[b-arr[b]]){
            q.push(b-arr[b]);
            visited[b-arr[b]] = true;
         }
        }
        }
        return false;
    }
};