class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int& x:nums){
            if(x==0)
                x=-1;
        }
        unordered_map<int,int> mpp; // sum,index
        mpp[0]=-1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.count(sum))
                ans=max(ans,i-mpp[sum]);
            else
                mpp[sum]=i;
        }
        for(int& x:nums){
            if(x==-1)
                x=0;
        }
        return ans;
    }
};