class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>& lastEle=res.back();
            if(intervals[i][0]<=lastEle[1])  lastEle[1]=max(lastEle[1],intervals[i][1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};