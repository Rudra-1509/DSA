class Solution {
public:
    bool helper(vector<int>& nums,int sum){
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<n+1;i++)    dp[i][0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return false;
        sum/=2;
        return helper(nums,sum);
    }
};