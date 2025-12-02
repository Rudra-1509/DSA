class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     vector<int> dp(n,1);
    //     for(int i=1;i<m;i++){
    //         for(int j=1;j<n;j++){
    //             dp[j]=dp[j-1]+dp[j];
    //         }
    //     }
    //     return dp[n-1];
    // }

    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int R=min(m-1,n-1);
        long double ans=1;
        for(int i=1;i<=R;i++){
            ans*=(double)(N-i+1)/i;
        }
        return (int)llround(ans);
    }
};