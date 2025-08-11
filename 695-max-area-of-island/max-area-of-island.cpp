class Solution {
public:
    int dfs(vector<vector<int>>& grid,int m,int n,int r,int c){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==0)   return 0;
        grid[r][c]=0;
        return    1+dfs(grid,m,n,r+1,c)+
                    dfs(grid,m,n,r-1,c)+
                    dfs(grid,m,n,r,c+1)+
                    dfs(grid,m,n,r,c-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,m,n,i,j);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};