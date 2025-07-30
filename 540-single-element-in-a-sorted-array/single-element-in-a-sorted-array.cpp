class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(mid%2==1)    mid--;    
            if(nums[mid]==nums[mid+1]){ //even and odd idx same ele so the single hasnt come yet
                left=mid+2;
            }else{
                right=mid;
            }
        }
        return nums[left];
    }
};