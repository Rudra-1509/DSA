class Solution {
public:
    vector<vector<int>> nav={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int r,int c,int m,int n){
        return (r>=0 && r<m && c>=0 && c<n);
    }
    int dfs(vector<vector<int>>& grid,int m,int n,int r,int c){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==0)   return 0;
        grid[r][c]=0;
        return    1+dfs(grid,m,n,r+1,c)+
                    dfs(grid,m,n,r-1,c)+
                    dfs(grid,m,n,r,c+1)+
                    dfs(grid,m,n,r,c-1);
    }
    int bfs(vector<vector<int>>& grid,int m,int n,int r,int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]=0;
        int area=1;
        while(!q.empty()){
            pair<int,int> cur=q.front();q.pop();
            for(int i=0;i<4;i++){
                int newr=cur.first+nav[i][0];
                int newc=cur.second+nav[i][1];
                if(isValid(newr,newc,m,n) && grid[newr][newc]==1){
                    q.push({newr,newc});
                    grid[newr][newc]=0;
                    area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=bfs(grid,m,n,i,j);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};