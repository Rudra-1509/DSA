class Solution {
public:
    void helper(vector<int>& nums,int ind,vector<int>& path,vector<vector<int>>& res){
        if(ind==nums.size()){
            res.push_back(path);
            return;
        }
        path.push_back(nums[ind]);
        helper(nums,ind+1,path,res);
        path.pop_back();
        helper(nums,ind+1,path,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(nums,0,path,res);
        return res;
    }
};