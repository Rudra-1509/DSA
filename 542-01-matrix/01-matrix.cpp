class Solution {
public:
    bool isSafe(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    vector<vector<int>> nav={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto[i,j]=q.front();q.pop();
            for(auto d:nav){
                int ni=i+d[0];
                int nj=j+d[1];
                if(isSafe(ni,nj,m,n) && res[ni][nj]==-1){
                    q.push({ni,nj});
                    res[ni][nj]=res[i][j]+1;
                }
            }
        }
        return res;
    }      
};