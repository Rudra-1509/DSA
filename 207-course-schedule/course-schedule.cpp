class Solution {
public:
    bool dfs(int node,vector<bool>& visited, vector<vector<int>>& adjList,vector<bool>& path){
        visited[node]=true;
        path[node]=true;
        for(int& neighbour:adjList[node]){
            if(!visited[neighbour]){
                if(!dfs(neighbour,visited,adjList,path))     return false;
            }
            else if(path[neighbour])    return false;
        }
        path[node]=false;
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