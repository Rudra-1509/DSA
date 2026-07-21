class Solution {
public:
    // bool isValid(vector<int>& nums,int mid, int k){
    //     int sticks=0,sum=0;
    //     for(int x:nums){
    //         sum+=x;
    //         if(sum>mid){
    //             sticks++;
    //             sum=x;
    //         }
    //     }
    //     return sticks+1<=k;
    // }

    // int splitArray(vector<int>& nums, int k) {
    //     int left=*max_element(nums.begin(),nums.end());
    //     int right=accumulate(nums.begin(),nums.end(),0);
    //     while(left<right){
    //         int mid=left+(right-left)/2;
    //         if(isValid(nums,mid,k)) right=mid;
    //         else left=mid+1;
    //     }
    //     return left;
    // }

    int splitArray(vector<int>& nums, int K) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(K+1,INT_MAX));
        dp[0][0]=0;
        for(int k=1;k<=K;k++){
            for(int i=1;i<=n;i++){
                int costSum=0;
                for(int j=i;j>0;j--){
                    costSum+=nums[j-1];
                    dp[i][k]=min(dp[i][k],max(dp[j-1][k-1],costSum));
                }
            }
        }
        return dp[n][K];
    }
};