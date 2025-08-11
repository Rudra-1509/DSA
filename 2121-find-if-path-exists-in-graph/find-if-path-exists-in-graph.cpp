class Solution {
public:
    bool dfs(int source, int destination,unordered_map<int,vector<int>>& adjList,vector<bool>& visited){
        if(source==destination) return true;
        visited[source]=true;
        for(auto neighbour:adjList[source]){
            if(!visited[neighbour])
                if(dfs(neighbour,destination,adjList,visited))  return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adjList;
        vector<bool> visited(n,false);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return dfs(source,destination,adjList,visited);
    }
};