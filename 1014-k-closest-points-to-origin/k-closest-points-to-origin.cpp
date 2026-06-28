class Solution {
private:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            long long dist1=a[0]*a[0]+a[1]*a[1];
            long long dist2=b[0]*b[0]+b[1]*b[1];
            return dist1<dist2;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<long long,vector<int>>> pq;
        for(auto& point: points){
            long long dist=1LL*point[0]*point[0]+1LL*point[1]*point[1];
            pq.push({dist,point});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};