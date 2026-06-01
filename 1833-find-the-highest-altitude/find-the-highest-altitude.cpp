class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,n=gain.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=gain[i];
            if(gain[i]>0)  ans=max(ans,sum);
        }
        return ans;
    }
};