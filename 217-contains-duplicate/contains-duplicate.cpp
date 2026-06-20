class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size()-1;i++){
    //         if(nums[i]==nums[i+1])  return true;
    //     }
    //     return false;
    // }

        unordered_map<int,int> mpp;
        for(int x:nums){
        if(mpp.count(x))    return true;
        else    mpp[x]++;
        }
        return false;
    }
};