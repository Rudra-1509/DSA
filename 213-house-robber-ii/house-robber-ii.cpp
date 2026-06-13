class Solution {
public:
    int helper(vector<int>& arr){
        int n=arr.size();
        if(n==1)    return arr[0];
        vector<int> dp(n,0);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> arr1,arr2;
        for(int i=0;i<n;i++){
            if(i!=0)        arr1.push_back(nums[i]);
            if(i!=n-1)      arr2.push_back(nums[i]);
        }
        return max(helper(arr1),helper(arr2));
    }
};