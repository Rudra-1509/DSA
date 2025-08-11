class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited,int i){
        visited[i]=true;
        for(int& key:rooms[i]){
            if(!visited[key])
                dfs(rooms,visited,key);
        }
    }
    void bfs(vector<vector<int>>& rooms,vector<bool>& visited,int i){
        queue<int> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int& key:rooms[cur]){
                if(!visited[key]){
                    visited[key]=true;
                    q.push(key);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n=rooms.size();
        vector<bool> visited(n,false);
        bfs(rooms,visited,0);
        for(bool flag:visited){
            if(!flag)   return false;
        }
        return true;
    }
};