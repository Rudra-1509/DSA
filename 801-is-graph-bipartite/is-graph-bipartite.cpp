class Solution {
public:
    bool dfs(int node,int color,vector<vector<int>>& graph,vector<int>& colors){
        colors[node]=color;
        for(int neigh:graph[node]){
            if(colors[neigh]==-1){
                if(dfs(neigh,1-color,graph,colors)==false)  
                    return false;
            }
            else if(colors[neigh]==colors[node])    return false;
        }
        return true;
    }
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int V=graph.size();
    //     vector<int> colors(V,-1);
    //     for(int i=0;i<V;i++){
    //         if(colors[i]==-1){
    //             if(dfs(i,0,graph,colors)==false)
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> colors(V,-1);
        for(int i=0;i<V;i++){
            if(colors[i]==-1){
                queue<pair<int,int>> q;
                q.push({i,0});
                colors[i]=0;
                while(!q.empty()){
                    auto [cur,col]=q.front();q.pop();
                    for(auto neigh:graph[cur]){
                        if(colors[neigh]==-1){
                            q.push({neigh,1-col});
                            colors[neigh]=1-col;
                        }
                        if(colors[neigh]==col)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};