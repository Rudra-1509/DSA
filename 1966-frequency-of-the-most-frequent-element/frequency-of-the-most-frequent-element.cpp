class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());   
        int l=0,ans=0;
        long long sum=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while((long long)(r-l+1)*nums[r]-sum > k)
                sum-=nums[l++];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};