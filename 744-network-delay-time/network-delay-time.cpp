class Solution {
using edge=pair<int,int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> adjList(n+1);
        for(auto t:times){
            int u=t[0],v=t[1],w=t[2];
            adjList[u].push_back({w,v});
        }
        priority_queue<edge,vector<edge>,greater<edge>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[0]=-1;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [curtime,u]=pq.top();pq.pop();
            if(dist[u]<curtime) continue;
            for(auto [time,neigh]: adjList[u]){
                if(dist[neigh]> curtime+time){
                    dist[neigh]=curtime+time;
                    pq.push({dist[neigh],neigh});
                }
            }
        }

        int ans=0;
        for(int x:dist){
            ans=max(ans,x);
        }
        if(ans==INT_MAX)    return -1;
        return ans;
    }
};