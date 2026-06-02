class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,sum=0;
        unordered_map<int,int> mpp;
        mpp[0]++;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.count(sum-k))    ans+=mpp[sum-k];
            mpp[sum]++;
        }
        return ans;
        
    }
};