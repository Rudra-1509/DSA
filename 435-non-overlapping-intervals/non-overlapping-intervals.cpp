class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
            [](auto &a,auto &b){
                return a[1]<b[1];
            });
        int end=intervals[0][1],keep=1,n=intervals.size();
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=end){
                keep++;
                end=intervals[i][1];
            }
        }
        return n-keep;
    }
};