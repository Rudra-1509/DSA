class Solution {
public:
    struct node{
        int cost;
        int city;
        int flightCount;

        bool operator>(const node& other)const {
            return cost>other.cost;
        }
    };
    using edge=pair<int,int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<edge>> adjList(n);
        for(auto f:flights){
            int u=f[0],v=f[1],w=f[2];
            adjList[u].push_back({w,v});
        }
        vector<vector<int>> costs(n,vector<int>(k+2,INT_MAX));
        costs[src][0]=0;
        priority_queue<node,vector<node>,greater<node>> pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [curCost,curCity,flightCount]=pq.top();pq.pop();
            if(curCity==dst)    return curCost;
            if(flightCount>=k+1) continue;
            for(auto [cost,next]:adjList[curCity]){
                int newCost=curCost+cost;
                int newFlightCount=flightCount+1;
                if(costs[next][newFlightCount]>newCost){
                    costs[next][newFlightCount]=newCost;
                    pq.push({newCost,next,newFlightCount});
                }
            }
        }
        // int ans=INT_MAX;
        // for(int flights=0;flights<=k+1;flights++){
        //     ans=min(ans,costs[dst][flights]);
        // }
        // return ans==INT_MAX? -1:ans;

        return -1;
    }
};