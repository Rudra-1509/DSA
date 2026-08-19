class Solution {
public:
    int n;
    vector<int> states;
    bool dfs(int u,vector<vector<int>>& dp,vector<vector<int>>& adjList,string& colors,int& ans){
        if(states[u]==1)    return false;
        if(states[u]==2)    return true;
        states[u]=1;
        for(auto v:adjList[u]){
                if(!dfs(v,dp,adjList,colors,ans))
                    return false;
        }
        
        for(int i=0;i<26;i++){
            for(auto v:adjList[u])
                dp[u][i]=max(dp[u][i],dp[v][i]);
            if(colors[u]==i+'a')
                dp[u][i]++;
            ans=max(ans,dp[u][i]);
        }
        states[u]=2;
        return true;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n=colors.size();
        states.assign(n,0);
        vector<vector<int>> adjList(n);
        for(auto& e:edges){
            int u=e[0],v=e[1];
            adjList[u].push_back(v);
        }
        vector<vector<int>> dp(n,vector<int>(26,0));
        int ans=0;
        for(int i=0;i<n;i++){
            if(states[i]==0)
                if(!dfs(i,dp,adjList,colors,ans))
                    return -1;
        }
        return ans;
    }
};