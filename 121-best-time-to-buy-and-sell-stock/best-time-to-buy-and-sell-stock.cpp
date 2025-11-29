class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],cost=0;
        for(int i=1;i<prices.size();i++){
            
            cost=max(cost,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return cost;
    }
};