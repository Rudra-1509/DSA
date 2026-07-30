class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total=accumulate(nums.begin(),nums.end(),0LL);
        int rem=total%p;
        if(rem==0)  return 0;
        int curSum=0,ans=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            curSum=(curSum+nums[i])%p;
            int need=(curSum-rem+p)%p;
            if(mpp.count(need)) ans=min(ans,i-mpp[need]);
            mpp[curSum]=i;
        }
        return ans==nums.size()?-1:ans;
    }
};