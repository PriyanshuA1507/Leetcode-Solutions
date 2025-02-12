class Twitter {
public:
using p = pair<int,int>;
int timestamp = 0;
 unordered_map<int,vector<p>>m;
  unordered_map<int,unordered_set<int>>fl;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        m[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<p> pq;
        vector<int> ans;
        for(auto a:m[userId]){
          pq.push(a);
        }
        for(auto a:fl[userId]){
         for(auto b:m[a]){  
          pq.push(b);
         }
        }

         while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
      if (followerId != followeeId) {
            fl[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        fl[followerId].erase(followeeId);
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