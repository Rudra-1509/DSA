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
        return helper(text1,text2,m,n,dp);
    }
};