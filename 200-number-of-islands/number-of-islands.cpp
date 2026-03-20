class Solution {
public:
    int r,c;
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    bool isSafe(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='V';
        for(int k=0;k<4;k++){
            int newi=i+nav[k][0];
            int newj=j+nav[k][1];
            if(isSafe(newi,newj) && grid[newi][newj]=='1')
                dfs(newi,newj,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        r=grid.size(),c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                count++;
                dfs(i,j,grid);
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='V')
                    grid[i][j]='1';
            }
        }
        return count;
    }
};