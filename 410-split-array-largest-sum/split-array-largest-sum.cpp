class Solution {
public:
    bool canSplit(vector<int>&nums,int k,int sum){
        int sticks=0,curSum=0;
        for(int num:nums){
            curSum+=num;
            if(curSum>sum){
                sticks++;
                curSum=num;
            }
        }
        return (sticks+1)<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        while(left<right){
            int mid=left+(right-left)/2;
            if(canSplit(nums,k,mid)){//this is a potential ans but we will try to find even smaller ans
                right=mid;
            }
            else{//we r requiring much more sticks this means the sum or mid is too small compared to the nums
                left=mid+1;
            }
        }
        return left;
    }
};