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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n=rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,visited,0);
        for(bool flag:visited){
            if(!flag)   return false;
        }
        return true;
    }
};