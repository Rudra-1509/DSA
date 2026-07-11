class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=0,mini=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=max(nums[i]-mini,ans);
            mini=min(nums[i],mini);
        }
        return ans==0? -1:ans;
    }
};