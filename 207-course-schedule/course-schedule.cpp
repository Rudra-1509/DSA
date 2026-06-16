class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adjList,vector<bool>& visited,vector<bool>& path){
        visited[node]=true;
        path[node]=true;
        for(int neigh:adjList[node]){
            if(!visited[neigh]){
                if(! dfs(neigh,adjList,visited,path))   return false;
            }
            else if(path[neigh])    
                return false;
        }
        path[node]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto edge:prerequisites){
            int u=edge[0],v=edge[1];
            adjList[v].push_back(u);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,adjList,visited,path))    return false;
            }
        }
        return true;
    }
};