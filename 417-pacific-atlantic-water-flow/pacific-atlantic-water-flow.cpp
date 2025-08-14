class Solution {
public:
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    bool isValid(int i,int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>>& visited){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int newi=i+nav[k][0];
            int newj=j+nav[k][1];
            if(isValid(newi,newj) && !visited[newi][newj] && heights[i][j]<=heights[newi][newj])
                dfs(newi,newj,heights,visited);
        }
    }

    void bfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            pair<int,int> cur=q.front();q.pop();
            for(int k=0;k<4;k++){
            int newi=cur.first+nav[k][0];
            int newj=cur.second+nav[k][1];
            if(isValid(newi,newj) && !visited[newi][newj] && heights[newi][newj]>=heights[cur.first][cur.second]){
                visited[newi][newj]=true;
                q.push({newi,newj});
            }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            bfs(i,0,heights,pac);
            bfs(i,n-1,heights,atl);
        }
        for(int j=0;j<n;j++){
            bfs(0,j,heights,pac);
            bfs(m-1,j,heights,atl);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])  result.push_back({i,j});
            }
        }
        return result;
    }
};