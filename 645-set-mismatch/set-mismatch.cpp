class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n){
            int corIdx=nums[i]-1;
            if(nums[corIdx]==nums[i])   i++;
            else    swap(nums[corIdx],nums[i]);
        }

        for(i=0;i<n;i++){
            if(nums[i]-1!=i)    return {nums[i],i+1};
        }
        return {};
    }
};