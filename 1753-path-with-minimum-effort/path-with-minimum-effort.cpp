class Solution {
public:
    int m,n;
    using edge=pair<int,pair<int,int>>;
    bool isSafe(int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> nav={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        priority_queue<edge,vector<edge>,greater<edge>> pq;   
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto [curwt,cell]=pq.top();
            auto [i,j]=cell;
            pq.pop();
            if(dist[i][j]<curwt) continue;
            for(auto& d:nav){
                int ni=i+d[0];
                int nj=j+d[1];
                if(isSafe(ni,nj)){
                    int diff=abs(heights[i][j]-heights[ni][nj]);
                    if(max(curwt,diff)<dist[ni][nj]){
                        dist[ni][nj]=max(curwt,diff);
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                    
                }
            }  
        }
        return dist[m-1][n-1];
    }

};