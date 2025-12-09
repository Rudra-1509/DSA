class Solution {
public:
    // void helper(vector<pair<int,int>>& vis,vector<vector<int>>& res,vector<int>& path){
    //     if(path.size()==vis.size()){
    //         res.push_back(path);
    //         return;
    //     }
    //     for(int i=0;i<vis.size();i++){
    //         if(!vis[i].second){
    //             vis[i].second=1;
    //             path.push_back(vis[i].first);
    //             helper(vis,res,path);
    //             path.pop_back();
    //             vis[i].second=0;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<pair<int,int>> vis;
    //     for(int i=0;i<nums.size();i++){
    //         vis.push_back({nums[i],0});
    //     }
    //     vector<vector<int>> res;
    //     vector<int> path;
    //     helper(vis,res,path);
    //     return res;
    // }

    void helper(vector<int>& nums,int ind,vector<vector<int>>& res){
        if(ind>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            helper(nums,ind+1,res);
            swap(nums[ind],nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,0,res);
        return res;
    }







};