class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> mpp;
        for(int i=0;i<s.size();i++){
            if(!mpp.count(s[i]))
                mpp[s[i]]={i,-1};
        }
        for(int i=s.size()-1;i>=0;i--){
            if(mpp[s[i]].second==-1){
                mpp[s[i]].second=i;
            }
        }

        vector<pair<int,int>> merged,intervals;
        for(auto it:mpp)
            intervals.push_back(it.second);
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            auto [s,e]=intervals[i];
            if(s<merged.back().second){
                merged.back().second=max(e,merged.back().second);
            }
            else{
                merged.push_back({s,e});
            }
        }
        vector<int> res;
        for(auto&[l,r]: merged)
            res.push_back(r-l+1);
        return res;
    }
};