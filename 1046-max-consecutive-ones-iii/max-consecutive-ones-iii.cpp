class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,left=0,countOf1=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==1)  countOf1++;
            while(right-left+1-countOf1>k){
                if(nums[left]==1)   countOf1--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;   
    }
};