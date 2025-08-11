class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int i){
        visited[i]=true;
        for(int j=0;j<visited.size();j++){
            if(isConnected[i][j]==1 && !visited[j])
                dfs(isConnected,visited,j);
        }
    }
    void bfs(vector<vector<int>>& isConnected,vector<bool>& visited,int i){
        queue<int> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int j=0;j<visited.size();j++){
                if(isConnected[cur][j]==1 && !visited[j]){
                    visited[j]=true;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(isConnected,visited,i);
            }
        }
        return count;
    }
};