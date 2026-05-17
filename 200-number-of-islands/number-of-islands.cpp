class Solution {
public:
    int r,c;
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    bool isSafe(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& vis,queue<pair<int,int>>& q){
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            auto [rr,cc]=q.front();q.pop();
            for(int k=0;k<4;k++){
                int nr=rr+nav[k][0];
                int nc=cc+nav[k][1];
                if(isSafe(nr,nc) && !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        r=grid.size(),c=grid[0].size();
        int ans=0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid,i,j,vis,q);
                    ans++;
                }
            }
        }
        return ans;
    }
};