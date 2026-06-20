class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size(),ans=1;
    //     vector<int> dp(n,1);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<i;j++){
    //             if(nums[i]>nums[j]){
    //                 dp[i]=max(dp[i],1+dp[j]);//1+dp[j] means including the current num in the subseq
    //             }
    //         }
    //         ans=max(ans,dp[i]);
    //     }
    //     return ans;
    // }

    int lowerBound(vector<int>& arr,int x){
        int low=0,high=arr.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(x>arr[mid]) low=mid+1;
            else    high=mid;     
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(tails.empty() || tails.back()<nums[i]){
                tails.push_back(nums[i]);
                ans++;
            }
            else{
                int lb=lowerBound(tails,nums[i]);
                tails[lb]=nums[i];
            }
        }
        return ans;
    }
};