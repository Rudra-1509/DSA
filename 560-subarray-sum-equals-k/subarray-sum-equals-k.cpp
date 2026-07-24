class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]++;
        int sum=0,ans=0;
        for(int x:nums){
            sum+=x;
            ans+=mpp[sum-k];
            mpp[sum]++;
        }
        return ans;
    }
};