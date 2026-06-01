class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,n=gain.size();
        vector<int> preSum(n+1,0);
        for(int i=0;i<n;i++){
            preSum[i+1]=preSum[i]+gain[i];
            if(gain[i]>0)  ans=max(ans,preSum[i+1]);
        }
        return ans;
    }
};