class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n=nums.size();
        vector<vector<double>> dp(n+1,vector<double>(K+1,INT_MIN));
        dp[0][0]=0;
        for(int k=1;k<=K;k++){
            for(int i=1;i<=n;i++){
                double costSum=0;
                for(int j=i;j>0;j--){
                    costSum+=nums[j-1];
                    double costAvg=costSum/(i-j+1);
                    dp[i][k]=max(dp[i][k],dp[j-1][k-1]+costAvg);
                }
            }
        }
        return dp[n][K];
    }
};