class Solution {
public:
    void helper(vector<int>& candidates,int ind, int target,
    vector<int>& path,vector<vector<int>>& result){
        if(target < 0)    return;
        if(target==0){
            result.push_back(path);
            return;
        }

        for(int i=ind;i<candidates.size();i++){
            if(target<candidates[i]) break;
            path.push_back(candidates[i]);
            helper(candidates,i,target-candidates[i],path,result);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,target,path,result);
        return result;
    }
};