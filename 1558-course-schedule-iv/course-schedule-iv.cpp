class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        for(auto& p:prerequisites){
            int i=p[0],j=p[1];
            dp[i][j]=true;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    dp[i][j]=dp[i][j] || (dp[i][k] && dp[k][j]);
            }
        }
        vector<bool> res;
        for(auto& q:queries){
            int i=q[0],j=q[1];
            res.push_back(dp[i][j]);
        }
        return res;
    }
};