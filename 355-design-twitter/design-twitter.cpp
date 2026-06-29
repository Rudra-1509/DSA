class Twitter {
private:
    struct node{
        int time;
        int index;
        int userId;
        int tweetId;
    };
    struct cmp{
        bool operator()(const node& a,const node& b){
            return a.time< b.time;
        }
    };
    unordered_map<int,unordered_set<int>> adjList;
    unordered_map<int,vector< pair<int,int> >> tweets;
    int timer;
    using PQ = priority_queue<node, vector<node>, cmp>;
    void pushIntoHeap(PQ& pq,int userId){
        if(tweets[userId].empty())  return;
        int n=tweets[userId].size();
        auto& [time,tweetId]=tweets[userId][n-1];
        pq.push({time,n-1,userId,tweetId});
    }
    void pushNext(PQ& pq,node& cur){
        if(cur.index==0)    return;
        auto [time,tweetId]=tweets[cur.userId][cur.index-1];
        pq.push({time,cur.index-1,cur.userId,tweetId});
    }
public:
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<node,vector<node>,cmp> pq;
        pushIntoHeap(pq,userId);
        for(int neigh:adjList[userId]){
            pushIntoHeap(pq,neigh);
        }
        while(!pq.empty() && res.size()<10){
            node cur=pq.top();pq.pop();
            res.push_back(cur.tweetId);
            pushNext(pq,cur);
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId==followeeId) return;
        adjList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        adjList[followerId].erase(followeeId);
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