class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);//1+dp[j] means including the current num in the subseq
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};