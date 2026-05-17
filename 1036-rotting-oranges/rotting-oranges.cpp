class Solution {
public:
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int m,int n,int r,int c){
        return r>=0 && r<m && c>=0 && c<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size(),freshOranges=0,time=0;
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    freshOranges++;
            }
        }
        while(freshOranges && !q.empty()){
            int sz=q.size();
            time++;
            for(int l=0;l<sz;l++){
                auto [i,j]=q.front();q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+nav[k][0];
                    int nj=j+nav[k][1];
                    if(isValid(row,col,ni,nj) && grid[ni][nj]==1){
                        q.push({ni,nj});
                        grid[ni][nj]=2;
                        freshOranges--;
                    }
                }
            }
        }
        if(freshOranges)    return -1;
        return time;
    }
};