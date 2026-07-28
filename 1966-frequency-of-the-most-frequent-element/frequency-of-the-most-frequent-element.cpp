class Solution {
public:
    using LL=long long;
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int left=0,ans=0;
       LL sum=0;
       for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while((1LL*(right-left+1)*nums[right])-sum>k)
                sum-=nums[left++];
            ans=max(ans,right-left+1);
       }
       return ans;
    }
};