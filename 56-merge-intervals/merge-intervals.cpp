class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>> res;
     sort(intervals.begin(),intervals.end());
     res.push_back(intervals[0]);
     for(int i=1;i<intervals.size();i++){
        auto& curr=intervals[i];
        int start=curr[0],end=curr[1];
        auto& lastIv=res.back();
        if(start<=lastIv[1]){
            lastIv[1]=max(end,lastIv[1]);
        }
        else res.push_back(curr);
     }
     return res;   
    }
};