class Solution {
public:
    bool dfs(int source, int destination,unordered_map<int,vector<int>>& adjList,vector<bool>& visited){
        if(source==destination) return true;
        visited[source]=true;
        for(int& neighbour:adjList[source]){
            if(!visited[neighbour])
                if(dfs(neighbour,destination,adjList,visited))  return true;
        }
        return false;
    }

    bool bfs(int source, int destination,unordered_map<int,vector<int>>& adjList,vector<bool>& visited){
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int cur=q.front();q.pop();
            if(cur==destination)  return true;
            for(int& neighbour:adjList[cur]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
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
        return bfs(source,destination,adjList,visited);
    }
};