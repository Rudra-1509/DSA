class Solution {
public:
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    bool isValid(int i,int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>& visited){
        visited[i][j]=true;
        for(auto d:nav){
            int ni=d[0]+i,nj=d[1]+j;
            if(isValid(ni,nj) && !visited[ni][nj] && heights[ni][nj]>=heights[i][j])
                dfs(heights,ni,nj,visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            dfs(heights,i,0,pac);
            dfs(heights,i,n-1,atl);
        }
        for(int i=0;i<n;i++){
            dfs(heights,0,i,pac);
            dfs(heights,m-1,i,atl);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};