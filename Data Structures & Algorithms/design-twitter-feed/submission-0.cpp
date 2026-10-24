class Twitter {
private:
    int time = 0;
    priority_queue<tuple<int, int, int>> allTweets;
    unordered_map<int, unordered_set<int>> subsList;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        allTweets.push({time++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto tmp = allTweets;
        vector<int> ans;
        while(!tmp.empty()) {
            if(ans.size() == 10) break;
            int creatorId = get<2>(tmp.top());
            if(creatorId == userId || subsList[userId].count(creatorId)) ans.push_back(get<1>(tmp.top()));
            tmp.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        subsList[followerId].insert(followeeId);
        subsList[followerId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        subsList[followerId].erase(followeeId);
    }
};
