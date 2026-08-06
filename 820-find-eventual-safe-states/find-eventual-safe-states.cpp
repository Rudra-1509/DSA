class Solution {
public:
    vector<int> states;
    bool dfs(int node,vector<vector<int>>& graph){
        if(states[node]==1) return false;
        if(states[node]==2) return true;
        states[node]=1;
        for(int neigh:graph[node]){
            if(!dfs(neigh,graph)) return false;
        }
        states[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        states.assign(n,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            if(dfs(i,graph))
                res.push_back(i);
        }
        return res;
    }
};