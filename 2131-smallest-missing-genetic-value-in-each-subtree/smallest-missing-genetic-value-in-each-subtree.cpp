class Solution {
public:
    void dfs(int cur,vector<vector<int>>& children,unordered_set<int>& vis,unordered_set<int>& seen,vector<int>& nums){
        if(vis.count(cur))   return;
        vis.insert(cur);
        seen.insert(nums[cur]);
        for(int child:children[cur])
            dfs(child,children,vis,seen,nums);
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=parents.size(),indexof1=-1;
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            if(nums[i]==1)  indexof1=i;
        }
        if(indexof1==-1)    return res;
        unordered_set<int> seen,vis;
        int cur=indexof1,missing=1;
        vector<vector<int>> children(n);
        for(int i=1;i<n;i++)
            children[parents[i]].push_back(i);
        while(cur>=0){
            dfs(cur,children,vis,seen,nums);
            while(seen.count(missing))  
                missing++;
            res[cur]=missing; 
            cur=parents[cur];
        }
        return res;
    }
};