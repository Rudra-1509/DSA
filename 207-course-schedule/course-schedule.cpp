class Solution {
public:
 bool dfs(int node, vector<bool>& visited, vector<vector<int>>& adj, vector<bool>& path) {
        if (path[node]) return false;     // found a cycle
        if (visited[node]) return true;   // already processed safely

        visited[node] = true;
        path[node] = true;

        for (int neigh : adj[node]) {
            if (!dfs(neigh,visited, adj,  path)) return false;
        }

        path[node] = false; // backtrack
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto& edge:prerequisites){
            int u=edge[0],v=edge[1];
            adjList[v].push_back(u);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<numCourses;i++){
         if(!dfs(i,visited,adjList,path))       return false;
        }
        return true;
    }
};