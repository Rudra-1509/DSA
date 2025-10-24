class Solution {
public:
    int helper(string& text1, string& text2,int m,int n,vector<vector<int>>& dp){
        if(dp[m][n]!=-1)    return dp[m][n];
        if(m==0 || n==0)    return dp[m][n]=0;
        if(text1[m-1]==text2[n-1])      return dp[m][n]=1+helper(text1,text2,m-1,n-1,dp);
        else    return dp[m][n]=max(helper(text1,text2,m,n-1,dp) , helper(text1,text2,m-1,n,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return helper(text1,text2,m,n,dp);
        
        for(int i=0;i<m+1;i++)  dp[i][0]=0;
        for(int i=0;i<n+1;i++)  dp[0][i]=0;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1])  dp[i][j]=1+dp[i-1][j-1];
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};