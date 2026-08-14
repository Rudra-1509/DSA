class Solution {
private:
    int timer;
public:
    Solution(){
        timer=0;
    }
    void dfs(int node,int par,vector<vector<int>>& adjList,
            vector<int>& tin,vector<int>& low,vector<bool>& vis,vector<vector<int>>& res){
        vis[node]=true;
        tin[node]=low[node]=++timer;
        for(auto neigh:adjList[node]){
            if(neigh==par)  continue;
            if(!vis[neigh]){
                //tree edge
                dfs(neigh,node,adjList,tin,low,vis,res);
                //propagate
                low[node]=min(low[node],low[neigh]);
                //check for node--neigh
                if(low[neigh] > tin[node]) //we can't reach any ancestor
                    res.push_back({node,neigh});
            }
            else{
                //back edge(ancestor)
                low[node]=min(low[node],tin[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<vector<int>> adjList(n);
        for(auto& e:connections){
            int u=e[0],v=e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool> vis(n,false);
        vector<int> low(n,0);
        vector<int> tin(n,0);
        dfs(0,-1,adjList,tin,low,vis,res);
        return res;
    }
};