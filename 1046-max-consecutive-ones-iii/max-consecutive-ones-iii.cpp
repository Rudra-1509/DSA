class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,left=0,countOf0=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0)  countOf0++;
            while(countOf0>k){
                if(nums[left]==0)   countOf0--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;   
    }
};