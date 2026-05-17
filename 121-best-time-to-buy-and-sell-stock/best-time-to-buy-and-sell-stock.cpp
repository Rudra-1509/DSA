class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int sp=prices[i];
            int prof=sp-mini;
            mini=min(mini,sp);
            ans=max(ans,prof);
        }
        return ans;
    }
};