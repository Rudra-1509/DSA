class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1,0); //dp[i]=max score diff b/w current player and opponent starting from index i
        for(int i=n-1;i>=0;i--){
            int sum=0;
            dp[i]=INT_MIN;
            for(int k=0;k<3 && i+k<n ;k++){
                sum+=stoneValue[i+k];
                dp[i]=max(dp[i],sum-dp[i+k+1]);
            }
        }
        if(dp[0]==0)    return "Tie";
        else if(dp[0]>0)    return "Alice";
        else return "Bob";
    }
};