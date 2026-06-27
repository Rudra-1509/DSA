class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size();
        if(m+n!=s3.size())  return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++)
            dp[i][0]=s3[i-1]==s1[i-1] && dp[i-1][0];
        for(int i=1;i<=n;i++)
            dp[0][i]=s3[i-1]==s2[i-1] && dp[0][i-1];
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j]=   (s3[i+j-1]==s1[i-1] && dp[i-1][j]) || 
                            (s3[i+j-1]==s2[j-1] && dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};