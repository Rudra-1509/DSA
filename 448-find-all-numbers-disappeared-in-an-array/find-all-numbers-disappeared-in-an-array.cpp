class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i=0,n=nums.size();
        while(i<n){
            int corIdx=nums[i]-1;
            if(nums[corIdx]==nums[i])   i++;
            else    swap(nums[corIdx],nums[i]);
        }
        for(i=0;i<n;i++){
            if(nums[i]-1!=i)    res.push_back(i+1);
        }
        return res;
    }
};