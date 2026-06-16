class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses,0);
        vector<int> res;
        for(auto edge: prerequisites){
            int u=edge[0],v=edge[1];
            adjList[v].push_back(u);
            inDegree[u]++;
        }   
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            res.push_back(cur);
            for(int neigh: adjList[cur]){
                inDegree[neigh]--;
                if(inDegree[neigh]==0)  q.push(neigh);
            }
        }
        if(res.size()==numCourses)  return res;
        return {};
    }
};