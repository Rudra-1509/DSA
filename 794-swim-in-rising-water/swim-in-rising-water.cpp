class Solution {
public:
    int n;
    vector<vector<int>> nav={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i,int j){
        return i>=0 && j>=0 && i<n && j<n;
    }
    using edge=pair<int,pair<int,int>>;
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> times(n,vector<int>(n,INT_MAX));
        times[0][0]=grid[0][0];
        priority_queue<edge,vector<edge>,greater<edge>> pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            auto [curtime,cell]=pq.top();pq.pop();
            auto [i,j]=cell;
            if(times[i][j]<curtime)   continue;
            for(auto d:nav){
                int ni=i+d[0],nj=j+d[1];
                if(isSafe(ni,nj)){
                    int cost=max(curtime,grid[ni][nj]);
                    if(times[ni][nj]>cost){
                        times[ni][nj]=cost;
                        pq.push({cost,{ni,nj}});
                    }
                }
           }
        }
        return times[n-1][n-1];

    }
};