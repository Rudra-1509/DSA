class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int digitSum=0;
            int num=nums[i];
            while(num>0){
                digitSum+=num%10;
                num/=10;
            }
            if(mpp.count(digitSum)){
                ans=max(ans,nums[mpp[digitSum]]+nums[i]);
                if(nums[i]>nums[mpp[digitSum]])
                    mpp[digitSum]=i;
            }
            else    mpp[digitSum]=i;
        }
        return ans;
    }
};