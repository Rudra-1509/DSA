class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i]+k))    ans+=mpp[nums[i]+k];
            if(mpp.count(nums[i]-k))    ans+=mpp[nums[i]-k];
            mpp[nums[i]]++;
        }
        return ans;
    }
};