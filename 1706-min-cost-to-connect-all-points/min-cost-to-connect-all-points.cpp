class Solution {
public:
    using edge=pair<int,int>;//cost,index of pt
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        priority_queue<edge,vector<edge>,greater<edge>> pq;
        vector<bool> vis(n,false);
        vector<int> minCost(n,INT_MAX);
        pq.push({0,0});
        minCost[0]=0;
        while(!pq.empty()){
            auto [curCost,ind]=pq.top();pq.pop();
            int x=points[ind][0];
            int y=points[ind][1];
            if(vis[ind])    continue;
            vis[ind]=true;
            ans+=curCost;
            for(int i=0;i<n;i++){
                if(vis[i])  continue;
                int cost=abs(points[i][0]-x)+abs(points[i][1]-y);
                if(minCost[i]>cost){
                    minCost[i]=cost;
                    pq.push({cost,i});
                }
            }
        }
        return ans;
    }
};