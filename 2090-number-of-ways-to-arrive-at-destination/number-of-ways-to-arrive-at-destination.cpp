class Solution {
public:
    using edge=pair<long long,int>;
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<edge>> adjList(n);
        for(auto& r:roads){
            int u=r[0],v=r[1],w=r[2];
            adjList[u].push_back({w,v});
            adjList[v].push_back({w,u});
        }
        vector<long long> times(n,LLONG_MAX);
        vector<int> ways(n,0);
        times[0]=0;
        ways[0]=1;
        priority_queue<edge,vector<edge>,greater<edge>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [curTime,cur]=pq.top();pq.pop();
            if(times[cur]<curTime)  continue;
            for(auto [time,next]:adjList[cur]){
                long long newTime=curTime+time;
                if(times[next] > newTime){
                    times[next]=newTime;
                    ways[next]=ways[cur];
                    pq.push({times[next],next});
                }
                else if(times[next]==newTime)
                    ways[next]=(ways[next]+ways[cur])%MOD;
            }
        }
        return ways[n-1];
    }
};