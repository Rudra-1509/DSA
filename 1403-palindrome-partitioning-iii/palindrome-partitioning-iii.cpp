class Solution {
public:
    int palindromePartition(string s, int K) {
        int n=s.size();
        vector<vector<int>> dp1(n,vector<int>(n,0));
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]!=s[j])
                    dp1[i][j]=(len==2)? 1 : 1+dp1[i+1][j-1];
                else    dp1[i][j]=(len==2)? 0 : dp1[i+1][j-1];
            }
        }
        vector<vector<int>> dp2(n+1,vector<int>(K+1,INT_MAX));
        dp2[0][0]=0;
        for(int k=1;k<=K;k++){
            for(int i=1;i<=n;i++){
                for(int j=i;j>0;j--){
                    int cost=dp1[j-1][i-1];
                    if(dp2[j-1][k-1]!=INT_MAX)
                        dp2[i][k]=min(dp2[i][k],dp2[j-1][k-1]+cost);
                }
            }
        }
        return dp2[n][K];
    }
};