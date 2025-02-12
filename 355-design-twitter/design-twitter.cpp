class Twitter {
public:
 int timestamp = 0;
 unordered_map<int,vector<pair<int,int>>> tweets;
 unordered_map<int,unordered_set<int>> followers;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        //first ->timestamp //second->tweetsid
       priority_queue<pair<int,int>>pq;
       for(auto a:tweets[userId]){
       pq.push(a);
       }

       for(auto b:followers[userId]){
       // b->followers laake de dega
       for(auto c: tweets[b]){
      pq.push(c);
       }
       }

     while(ans.size()<10 && pq.size()!=0){
     auto a = pq.top();
     //second->tweets id
     ans.push_back(a.second);
     pq.pop();
     }
     return ans;
    }
    
    void follow(int followerId, int followeeId) {
     followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
      followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */