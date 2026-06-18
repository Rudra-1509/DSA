class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto it:times){
            int u=it[0],v=it[1],w=it[2];
            adjList[u].push_back({v,w});
        }
        vector<int> time(n+1,INT_MAX);
        //time,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [curtime,cur]=pq.top();pq.pop();
            if(curtime>time[cur])   continue;
            for(auto [neigh,wt]:adjList[cur]){
                if(time[neigh]>time[cur]+wt){
                    time[neigh]=time[cur]+wt;
                    pq.push({time[neigh],neigh});
                }
            }
            
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int x=time[i];
            if(x==INT_MAX)  return -1;
            ans=max(ans,x);
        }
        return ans;
    }
};