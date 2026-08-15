class Solution {
private:
    int m,n;
    int timer;
    bool isSafe(int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    const vector<vector<int>> nav={{-1,0},{1,0},{0,-1},{0,1}};
public:
    Solution(){
        timer=0;
    }
    void dfs(int i,int j,int pari,int parj,vector<vector<int>>& grid, vector<vector<int>>& vis, vector<vector<int>>& tin,
            vector<vector<int>>& low,vector<vector<int>>& isAP){
        vis[i][j]=1;
        tin[i][j]=low[i][j]=++timer;
        int children=0;
        for(auto& d:nav){
            int ni=i+d[0],nj=j+d[1];
            if(isSafe(ni,nj) && grid[ni][nj]){
                if(ni==pari && nj==parj)    continue;
                if(!vis[ni][nj]){
                    children++;
                    dfs(ni,nj,i,j,grid,vis,tin,low,isAP);
                    low[i][j]=min(low[i][j],low[ni][nj]);
                    if(low[ni][nj] >= tin[i][j] && pari!=-1)    isAP[i][j]=1;
                }
                else    low[i][j]=min(low[i][j],tin[ni][nj]);
            }
        }

        if(pari==-1 && parj==-1 && children>=2)     isAP[i][j]=1;
    }
    int minDays(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> tin(m,vector<int>(n,0));
        vector<vector<int>> low(m,vector<int>(n,0));
        vector<vector<int>> isAP(m,vector<int>(n,0));

        int components=0,noOf1=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    noOf1++;
                    if(!vis[i][j]){
                        components++;
                        dfs(i,j,-1,-1,grid,vis,tin,low,isAP);
                    }
                }
            }
        }
        if(components!=1)    return 0;
        bool existsAP=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isAP[i][j]){
                    existsAP=true;
                    break;
                }
            }
        }
        if(noOf1==1 || existsAP)    return 1;
        return 2;
    }
};