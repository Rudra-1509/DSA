class DetectSquares {
public:
    unordered_map<int,unordered_map<int,int>> mpp;
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        int x=point[0],y=point[1];
        mpp[x][y]++;
    }
    
    int count(vector<int> point) {
        int x=point[0],y=point[1],ans=0;
        for(auto& [y2,count]:mpp[x]){
            if(y==y2)   continue;
            int d=y2-y;
            ans+=mpp[x][y2]*mpp[x+d][y2]*mpp[x+d][y];
            ans+=mpp[x][y2]*mpp[x-d][y2]*mpp[x-d][y];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */