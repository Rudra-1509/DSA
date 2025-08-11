class Solution {
public:
    int m,n;
    bool isValid(int r,int c){
        return (r>=0 && r<m && c>=0 && c<n);
    }
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(!isValid(r,c) || grid[r][c]==0)  return 1;
        if(grid[r][c]==-1)  return 0;
        grid[r][c]=-1;
        return      dfs(grid,r+1,c)+
                    dfs(grid,r-1,c)+
                    dfs(grid,r,c+1)+
                    dfs(grid,r,c-1);
    }
    int bfs(vector<vector<int>>& grid,int r,int c){
        int peri=0;
        vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]=-1;
        while(!q.empty()){
            auto cur=q.front();q.pop();
            for(int i=0;i<4;i++){
                int newr=cur.first+nav[i][0];
                int newc=cur.second+nav[i][1];
                if(!isValid(newr,newc)|| grid[newr][newc]==0)   peri+=1;
                else if(grid[newr][newc]==1){
                    q.push({newr,newc});
                    grid[newr][newc]=-1;
                } 
            }
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return bfs(grid,i,j);
                }
            }
        }
        return 0;
    }
};