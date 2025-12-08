class Solution {
public:
    void helper(vector<int>& candidates,int ind, int target,
    vector<int>& path,vector<vector<int>>& result){
        if(ind >= candidates.size() || target < 0)    return;
        if(target==0){
            result.push_back(path);
            return;
        }

        for(int i=ind;i<candidates.size();i++){
            path.push_back(candidates[i]);
            helper(candidates,i,target-candidates[i],path,result);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        helper(candidates,0,target,path,result);
        return result;
    }
};