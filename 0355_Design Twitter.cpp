class Twitter {
    // struct Tweet{
    //     int tweetId;
    //     int userId;
    //     int timestamp;
    //     Tweet(int tweetId, int userId, int timestamp):tweetId(tweetId), userId(userId), timestamp(timestamp){}
    // }
    // // int TIMESTAMP;
    vector<pair<int, int>> tweets;
    unordered_map<int, set<int>> follows;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        // TIMESTAMP = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        set<int>& following = follows[userId];
        for (int i = (int)tweets.size() - 1; ans.size() < 10 && i >= 0; i--){
            if (tweets[i].first == userId || following.count(tweets[i].first)) ans.push_back(tweets[i].second);
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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
