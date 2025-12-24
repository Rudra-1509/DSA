class Solution {
public:
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int m,int n,int r,int c){
        return r>=0 && r<m && c>=0 && c<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        int freshOranges=0,time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)   
                    q.push({i,j});
                else if(grid[i][j]==1)
                    freshOranges++;
            }
        }
        while(!q.empty() && freshOranges){
            int size=q.size();
            time++;
            while(size--){
                auto [i,j]=q.front();q.pop();
                for(auto &d:nav){
                    int newi=i+d[0];
                    int newj=j+d[1];
                    if(isValid(m,n,newi,newj) && grid[newi][newj]==1){
                        grid[newi][newj]=2;
                        freshOranges--;
                        q.push({newi,newj});
                    }
                }
            }

        }
        if(freshOranges)    return -1;
        else    return time;
    }
};