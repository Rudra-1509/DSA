class Solution {
public:
    void helper(int ind,vector<int>& nums,vector<vector<int>>& res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            helper(ind+1,nums,res);
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0,nums,res);
        return res;
    }
};