class Solution {
public:
    void helper(vector<int>& candidates, int target,int ind,vector<vector<int>>& res,vector<int>& path){
        if(target<0)    return;
        if(ind==candidates.size()){
            if(target==0)
                res.push_back(path);
            return;
        }
        path.push_back(candidates[ind]);
        helper(candidates,target-candidates[ind],ind,res,path);
        path.pop_back();
        helper(candidates,target,ind+1,res,path);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        helper(candidates,target,0,res,path);
        return res;
    }
};
