class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),farthest=0;
        vector<bool> dp(n,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i] && (i+j)<n;j++){
                dp[i+j]=dp[i+j]||dp[i];
            }
        }
        return dp[n-1];
    }
};