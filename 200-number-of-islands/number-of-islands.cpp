class Solution {
public:
    bool isValid(int r,int c,int m,int n){
        return (r>=0 && r<m && c>=0 && c<n);
    }
    void dfs(vector<vector<char>>& grid,int r,int c,vector<vector<bool>>& visited,int m,int n){
        visited[r][c]=true;
        vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<4;i++){
            int newr=r+nav[i][0];
            int newc=c+nav[i][1];
            if(isValid(newr,newc,m,n) && !visited[newr][newc] && grid[r][c]=='1')
                dfs(grid,newr,newc,visited,m,n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,visited,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};