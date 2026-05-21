class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem=0,ans=0;
        while(numBottles>0){
            ans+=numBottles; //full->empty
            numBottles+=rem;
            rem=numBottles%numExchange;
            numBottles/=numExchange;
        }
        return ans;
    }
};