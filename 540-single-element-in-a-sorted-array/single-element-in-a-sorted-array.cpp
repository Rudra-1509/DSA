class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==nums[mid^1])  //checks for even odd pair
                l=mid+1;
            else    r=mid-1;
        }
        return nums[l];
    }
};