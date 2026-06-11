class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp; // sum,index
        mpp[0]=-1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i])?1:-1;
            if(mpp.count(sum))
                ans=max(ans,i-mpp[sum]);
            else
                mpp[sum]=i;
        }
        return ans;
    }
};