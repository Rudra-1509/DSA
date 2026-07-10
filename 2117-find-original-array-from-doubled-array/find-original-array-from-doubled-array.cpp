class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        sort(changed.begin(),changed.end());
        unordered_map<int,int> mpp;
        for(int x:changed)  mpp[x]++;
        int i=0;
        while(!mpp.empty() && i<changed.size()){
            int x=changed[i++];
            if(mpp.count(x) && mpp.count(x*2)){
                res.push_back(x);
                if(--mpp[x]==0) mpp.erase(x);
                if(--mpp[x*2]==0)   mpp.erase(x*2);
            }
        }
        if(mpp.empty())   return res;
        return {};
    }
};