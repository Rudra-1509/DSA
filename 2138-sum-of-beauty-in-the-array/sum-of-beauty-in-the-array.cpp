class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int> preMax(n,INT_MIN);
        vector<int> preMin(n,INT_MAX);
        for(int i=1;i<n;i++)
            preMax[i]=max(nums[i-1],preMax[i-1]);
        for(int i=n-2;i>=0;i--)
            preMin[i]=min(nums[i+1],preMin[i+1]);
        for(int i=1;i<=n-2;i++){
            if(nums[i]>preMax[i] && nums[i]<preMin[i])  ans+=2;
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]) ans+=1;
        }
        return ans;
    }
};