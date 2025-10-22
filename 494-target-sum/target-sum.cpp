class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int tg=sum-target;
        if(tg<0 || tg%2==1) return 0;
        tg/=2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(tg+1,0));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<tg+1;j++){
                if(nums[i-1]<=j)    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][tg];
    }
};