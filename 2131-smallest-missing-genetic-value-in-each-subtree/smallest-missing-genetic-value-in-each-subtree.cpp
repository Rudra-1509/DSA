class Solution {
public:
    void dfs(int cur,vector<vector<int>>& children,unordered_set<int>& visited,vector<int>& nums){
        if(visited.count(nums[cur]))   return;
        visited.insert(nums[cur]);
        for(int child:children[cur])
            dfs(child,children,visited,nums);
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=parents.size(),indexof1=-1;
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            if(nums[i]==1)  indexof1=i;
        }
        if(indexof1==-1)    return res;
        unordered_set<int> visited;
        int cur=indexof1,missing=1;
        vector<vector<int>> children(n);
        for(int i=1;i<n;i++)
            children[parents[i]].push_back(i);
        while(cur>=0){
            dfs(cur,children,visited,nums);
            while(visited.count(missing))  
                missing++;
            res[cur]=missing; 
            cur=parents[cur];
        }
        return res;
    }
};