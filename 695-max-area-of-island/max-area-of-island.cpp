class Solution {
public:
    int maxArea=0;
    void dfs(vector<vector<int>>& grid,int m,int n,int r,int c,int& area){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==0)   return;
        grid[r][c]=0;
        area++;
        maxArea=max(maxArea,area);
        dfs(grid,m,n,r+1,c,area);
        dfs(grid,m,n,r-1,c,area);
        dfs(grid,m,n,r,c+1,area);
        dfs(grid,m,n,r,c-1,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(grid,m,n,i,j,area);
                }
            }
        }
        return maxArea;
    }
};