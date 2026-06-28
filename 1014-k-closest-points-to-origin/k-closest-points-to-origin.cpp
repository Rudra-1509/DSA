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
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        for(auto& point: points){
            pq.push(point);
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};