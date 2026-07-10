class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n & 1)   return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int> mpp;
        for(int x:changed)  mpp[x]++;
        vector<int> res;
        for(int x:changed){
            if(mpp[x]==0)   continue;
            if(mpp[2*x]==0) return {};
            mpp[x]--;
            mpp[2*x]--;
            res.push_back(x);
        }
        return res;
    }
};