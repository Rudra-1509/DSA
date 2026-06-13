class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),ans=INT_MAX;
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++)
            pref[i+1]=pref[i]+nums[i];
        for(int i=0;i<n;i++){
            long long need=pref[i]+target;
            auto it=lower_bound(pref.begin(),pref.end(),need);
            if(it!=pref.end()){
                int j=it-pref.begin();
                ans=min(ans,j-i);
            }
        }
        return ans==INT_MAX? 0 : ans;
    }
};