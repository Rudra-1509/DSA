class Solution {
public:
    bool helper(vector<int>& nums,int n,int target,vector<vector<bool>>& dp){
        for(int i=0;i<n+1;i++)  dp[i][0]=true;
        for(int i=1;i<target+1;i++) dp[0][i]=false;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1)  return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        return helper(nums,n,target,dp);
    }
};