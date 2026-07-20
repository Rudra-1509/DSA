class Solution {
public:
    void process(vector<int>& nums,unordered_map<int,int>& mpp){
        unordered_set<int> vis;
        for(int& num:nums){
            if(vis.count(num))  continue;
            vis.insert(num);
            mpp[num]++;
        }
    }

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        unordered_map<int,int> mpp;
        process(nums1,mpp);
        process(nums2,mpp);
        process(nums3,mpp);
        for(auto it:mpp){
            if(it.second>=2)    res.push_back(it.first);
        }
        return res;
    }
};