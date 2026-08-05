class Solution {
public:
    vector<vector<int>> nav={{-1,0},{1,0},{0,1},{0,-1}};
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),dist=-1;
        vector<vector<int>> res(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            dist++;
            while(sz--){
                auto [i,j]=q.front();q.pop();
                res[i][j]=dist;
                for(auto d:nav){
                    int ni=i+d[0],nj=j+d[1];
                    if(isValid(ni,nj,m,n) && mat[ni][nj]!=-1){
                        q.push({ni,nj});
                        mat[ni][nj]=-1;
                    }
                }
            }
        }

        return res;
    }
};