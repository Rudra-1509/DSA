class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<long long,vector<int> >> pq;
        for(auto& p:points){
            int dist=1LL*p[0]*p[0]+p[1]*p[1];
            pq.push({dist,p});
            if(pq.size()>k)     pq.pop();
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};