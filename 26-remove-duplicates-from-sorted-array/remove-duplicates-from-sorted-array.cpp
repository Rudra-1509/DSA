class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        int lastUniIdx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[lastUniIdx]){
                lastUniIdx++;
                swap(nums[i],nums[lastUniIdx]);
            }   
        }
        return lastUniIdx+1;

    }
};