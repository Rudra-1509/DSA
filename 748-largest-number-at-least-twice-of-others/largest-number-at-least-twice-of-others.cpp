class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first=INT_MIN,second=INT_MIN,idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==first || nums[i]==second)   continue;
            if(nums[i]>first){
                second=first;
                first=nums[i];
                idx=i;
            }
            else if(nums[i]>second)
                second=nums[i];
        }
        return first>=2*second ? idx:-1;
    }
};