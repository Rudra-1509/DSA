class Solution {
public:
    using edge=pair<double,int>;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n,0);
        prob[start_node]=1.0;
        vector<vector<edge>> adjList(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double wt=succProb[i];
            adjList[u].push_back({wt,v});
            adjList[v].push_back({wt,u});
        }
        priority_queue<edge,vector<edge>,less<edge>> pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [curProb,node]=pq.top();pq.pop();
            if(prob[node]>curProb)  continue;
            for(auto [p,neigh]:adjList[node]){
                double newProb=curProb*p;
                if(prob[neigh]<newProb){
                    prob[neigh]=newProb;
                    pq.push({newProb,neigh});
                }
            }
        }

        return prob[end_node];
    }
};