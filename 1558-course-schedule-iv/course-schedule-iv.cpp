class Solution {
public:
    // vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
    //                                  vector<vector<int>>& queries) {
    //     vector<vector<bool>> dp(n, vector<bool>(n, false));
    //     for (auto& p : prerequisites) {
    //         int i = p[0], j = p[1];
    //         dp[i][j] = true;
    //     }
    //     for (int k = 0; k < n; k++) {
    //         for (int i = 0; i < n; i++) {
    //             for (int j = 0; j < n; j++)
    //                 dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
    //         }
    //     }
    //     vector<bool> res;
    //     for (auto& q : queries) {
    //         int i = q[0], j = q[1];
    //         res.push_back(dp[i][j]);
    //     }
    //     return res;
    // }

    void dfs(int u, vector<vector<int>>& adjList, vector<bool>& vis,vector<vector<bool>>& dp){
        vis[u]=true;
        for(auto v:adjList[u]){
            if(!vis[v])
                dfs(v,adjList,vis,dp);
            dp[u][v]=true;
            for(int i=0;i<adjList.size();i++){
                if(dp[v][i])
                    dp[u][i]=true;
            }
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<vector<int>> adjList(n);
        for(auto& p:prerequisites){
            int u=p[0],v=p[1];
            adjList[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            dfs(i,adjList,vis,dp);
        }
        vector<bool> res;
        for (auto& q : queries) {
            int i = q[0], j = q[1];
            res.push_back(dp[i][j]);
        }
        return res;
    }
};