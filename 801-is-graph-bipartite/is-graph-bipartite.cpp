class Solution {
public:
    //1->black 0->white
    int n;
    bool bfs(vector<vector<int>>& graph,vector<bool>& visited,vector<int>& colors){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
            q.push(i);
            visited[i]=true;
            colors[i]=1;
            }
            while(!q.empty()){
                int cur=q.front();q.pop();
                for(int neighbour:graph[cur]){
                    if(!visited[neighbour]){
                        if(colors[cur]==1){
                            q.push(neighbour);
                            colors[neighbour]=0;
                        }
                        else{
                            q.push(neighbour);
                            colors[neighbour]=1;
                        }
                        visited[neighbour]=true;
                    }
                    else{
                        if(colors[cur]==colors[neighbour])    return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        vector<bool> visited(n,false);
        vector<int> colors(n,-1);
        return bfs(graph,visited,colors);
    }
};