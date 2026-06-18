class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adjList,vector<bool>& vis,vector<bool>& path){
        vis[node]=true;
        path[node]=true;
        for(auto neigh:adjList[node]){
            if(!vis[neigh]){
                if(!dfs(neigh,adjList,vis,path))    return false;
            }
            else if(path[neigh])    return false;
        }
        path[node]=false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto& edge: prerequisites){
            int u=edge[0],v=edge[1];
            adjList[v].push_back(u);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(i,adjList,vis,path))    return false;
            }
        }
        return true;
    }
};