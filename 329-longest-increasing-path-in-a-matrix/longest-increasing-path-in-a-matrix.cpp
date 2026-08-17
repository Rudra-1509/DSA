class Solution {
private:
    int m,n;
    bool isSafe(int i,int j){
        return i>=0 && i<m &&j>=0 && j<n;
    }
    const vector<vector<int>> nav={{1,0},{-1,0},{0,-1},{0,1}};
public:
    int dfs(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[i][j])    return dp[i][j];
        int temp=0;
        for(auto& d:nav){
            int ni=i+d[0],nj=j+d[1];
            if(isSafe(ni,nj) && matrix[i][j] > matrix[ni][nj])
                    temp=max(temp,dfs(ni,nj,matrix,dp));
        }
        dp[i][j]=1+temp;
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};