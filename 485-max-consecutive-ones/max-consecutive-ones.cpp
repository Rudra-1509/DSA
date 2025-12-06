class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0,maxlen=0,count=0;
        for(int right=left;right<nums.size();right++){
            if(nums[right]==1)   count++;
            else if(nums[right]==0 || right==nums.size()){
                maxlen=max(maxlen,count);
                left=right+1;
                count=0;
            }
        }
        maxlen=max(maxlen,count);
        return maxlen;
    }
};