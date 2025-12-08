class Solution {
public:
    void helper(vector<int>& nums,int start,vector<vector<int>>& result,vector<int>& subset){
        result.push_back(subset);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1])   continue;
            subset.push_back(nums[i]);
            helper(nums,i+1,result,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        helper(nums,0,result,subset);
        return result;
    }
};