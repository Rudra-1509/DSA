class Solution {
public:
    //1->black 0->white
    int n;
    bool bfs(vector<vector<int>>& graph,vector<int>& colors){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
            q.push(i);
            colors[i]=1;
            }
            while(!q.empty()){
                int cur=q.front();q.pop();
                for(int neighbour:graph[cur]){
                    if(colors[neighbour]==-1){
                        if(colors[cur]==1){
                            q.push(neighbour);
                            colors[neighbour]=0;
                        }
                        else{
                            q.push(neighbour);
                            colors[neighbour]=1;
                        }
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
        vector<int> colors(n,-1);
        return bfs(graph,colors);
    }
};