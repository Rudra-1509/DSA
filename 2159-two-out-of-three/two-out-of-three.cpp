class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        unordered_map<int,int> mpp;
        unordered_set<int> vis;
        for(int num:nums1){
            if(vis.count(num))  continue;
            vis.insert(num);
            mpp[num]++;
        }
        vis.clear();
        for(int num:nums2){
            if(vis.count(num))  continue;
            vis.insert(num);
            mpp[num]++;
        }
        vis.clear();
        for(int num:nums3){
            if(vis.count(num))  continue;
            vis.insert(num);
            mpp[num]++;
        }
        for(auto it:mpp){
            if(it.second>=2)    res.push_back(it.first);
        }
        return res;
    }
};