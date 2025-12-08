class Solution {
public:
    void helper(vector<int>& candidates, int target, int ind,
    vector<int>& path,vector<vector<int>>& res){
        if(target<0)  return;
        if(target==0){
            res.push_back(path);
            return;
        }

        for(int i=ind;i<candidates.size();i++){
            if(target<candidates[i]) break;
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            path.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i+1,path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,path,res);
        return res;
    }
};