class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(auto& e:edges){
            dp[e[0]][e[1]]=e[2];
            dp[e[1]][e[0]]=e[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        int ans=-1,least=INT_MAX;
        for(int i=0;i<n;i++){
            int validCities=0;
            for(int j=0;j<n;j++){
                if(i==j)    continue;
                if(dp[i][j]<=distanceThreshold)
                    validCities++;
            }
            if(validCities<=least){
                least=validCities;
                ans=i;
            }
        }
        return ans;
    }
};