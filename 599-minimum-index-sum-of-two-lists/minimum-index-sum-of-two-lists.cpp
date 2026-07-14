class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int m=list1.size(),n=list2.size(),sum=INT_MAX;
        vector<string> res;
        unordered_map<string,int> mpp;
        for(int i=0;i<m;i++)
            mpp[list1[i]]=i;
        for(int i=0;i<n;i++){
            if(mpp.count(list2[i]))
                sum=min(sum,mpp[list2[i]]+i);
        }
        for(int i=0;i<n;i++){
            if(mpp.count(list2[i]) && (mpp[list2[i]]+i)==sum)
                res.push_back(list2[i]);
        }
        return res;
    }
};