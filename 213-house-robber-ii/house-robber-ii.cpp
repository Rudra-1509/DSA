class Solution {
public:
    int helper(int start,int end,vector<int>& nums){
        int n=end-start+1;
        if(n==1)    return nums[start];
        vector<int> dp(n,0);
        dp[0]=nums[start];
        dp[1]=max(dp[0],nums[start+1]);
        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i+start]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];
        int takeFirst=helper(0,n-2,nums);
        int takeLast=helper(1,n-1,nums);
        return max(takeFirst,takeLast);    
    }
};