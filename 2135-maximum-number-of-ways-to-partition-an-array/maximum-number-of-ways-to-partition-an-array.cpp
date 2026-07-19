class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        long long oldSum=pref[n-1];

        unordered_map<long long,int> left,right;
        for(int i=0;i<n-1;i++)
            right[pref[i]]++;
        int ans=0;
        if(oldSum%2==0)
            ans=right[oldSum/2];
        for(int i=0;i<n;i++){
            long long diff=k-nums[i];
            long long newSum=oldSum+diff;
            if(newSum%2==0){
                int count=0;
                count+=left[newSum/2]; //leftSum unaffected so check left as it stores all prefix sums before i
                count+=right[(oldSum-diff)/2]; //rightSum unaffected so check right as it stores all pref sums from i
                ans=max(ans,count);
            }
            if(i<n-1) right[pref[i]]--;
            left[pref[i]]++;
            
        }
        return ans;
    }
};