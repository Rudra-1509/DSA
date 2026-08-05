class Solution {
public:
    vector<vector<int>> nav={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int r,int c,int m,int n){
        return (r>=0 && r<m && c>=0 && c<n);
    }
    int dfs(vector<vector<int>>& grid,int m,int n,int r,int c){
        grid[r][c]=0;
        int sum=1;
        for(auto d:nav){
            int ni=r+d[0];
            int nj=c+d[1];
            if(isValid(ni,nj,m,n) && grid[ni][nj]==1){
                sum+=dfs(grid,m,n,ni,nj);
            }
        }
        return sum;
    }
    int bfs(vector<vector<int>>& grid,int m,int n,int r,int c){
        queue<pair<int,int>> q;
        int ans=0;
        q.push({r,c});
        grid[r][c]=0;
        while(!q.empty()){
            pair<int,int> cur=q.front();q.pop();
            ans++;
            for(auto d:nav){
                int ni=cur.first+d[0];
                int nj=cur.second+d[1];
                if(isValid(ni,nj,m,n) && grid[ni][nj]==1){
                    q.push({ni,nj});
                    grid[ni][nj]=0;
                }
            }
        }
        return ans;
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