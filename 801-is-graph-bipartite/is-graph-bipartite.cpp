class Solution {
public:
    //1->black 0->white
    int n;
    bool bfs(int i,vector<vector<int>>& graph,vector<int>& colors,int color){
            queue<int> q;
            q.push(i);
            colors[i]=color;
            
            while(!q.empty()){
                int cur=q.front();q.pop();
                for(int neighbour:graph[cur]){
                    if(colors[neighbour]==-1){
                        q.push(neighbour);
                        colors[neighbour]=1-colors[cur];
                    }
                    else{
                        if(colors[cur]==colors[neighbour])    return false;
                    }
                }
        }
        return true;
    }
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& colors,int color){
            colors[i]=color;
            for(int neighbour:graph[i]){
                if(colors[neighbour]==-1){
                        if(!dfs(neighbour,graph,colors,1-color))     
                            return false;   
                }
                else if(colors[i]==colors[neighbour])    return false;
            }
            return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int> colors(n,-1);
        // return bfs(graph,colors);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(!bfs(i,graph,colors,1))  return false;
            }
        }
        return true;
    }
};