class Solution {
public:
    int m,n;
    bool isValid(int i,int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        int freshOranges=0,time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }
        while(!q.empty() && freshOranges){
            int sz=q.size();
            time++;
            for(int lev=0;lev<sz;lev++){
                auto [i,j]=q.front();q.pop();
                for(auto d:nav){
                    int ni=d[0]+i,nj=d[1]+j;
                    if(isValid(ni,nj) && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        freshOranges--;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return freshOranges ? -1:time;
    }
};