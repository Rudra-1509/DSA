class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),sum=0,ans=0;
        unordered_map<int,int> mpp;
        mpp[0]++;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.count(sum-goal))    ans+=mpp[sum-goal];
            mpp[sum]++;
        }
        return ans;
    }
};