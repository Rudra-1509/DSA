class Solution {
public:
    void helper(vector<int>& nums, int ind, vector<vector<int>>& res, vector<int>& path){
        if(ind==nums.size()){
            res.push_back(path);
            return;
        }
        helper(nums,ind+1,res,path);

        path.push_back(nums[ind]);
        helper(nums,ind+1,res,path);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(nums,0,res,path);
        return res;
    }
};