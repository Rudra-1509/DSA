class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m=rides.size();
        sort(rides.begin(),rides.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        vector<int> ends;
        for(int i=0;i<m;i++)
            ends.push_back(rides[i][1]);
        vector<long long> dp(m+1,0);
        for(int i=1;i<=m;i++){
            int j=upper_bound(ends.begin(),ends.end(),rides[i-1][0])-ends.begin();
            long long profit=rides[i-1][2]+rides[i-1][1]-rides[i-1][0];
            dp[i]=max(dp[i-1],profit+dp[j]);
        }
        return dp[m];
    }
};