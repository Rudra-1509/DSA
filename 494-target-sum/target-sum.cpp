class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size(),x=target+sum;
        if(x & 1 || x<0)   return 0;
        x/=2;
        vector<vector<int>> dp(n+1,vector<int>(x+1,0));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<x+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][x];
    }
};