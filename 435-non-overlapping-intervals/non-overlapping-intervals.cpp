class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0,recent=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[recent][1]){
                count++;
                if(intervals[recent][1]>intervals[i][1])
                    recent=i;
            }
            else    recent=i;
        }
        return count;
    }
};