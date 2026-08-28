class Solution {
public:
    const int MOD=1e9+7;
    const int INV2=500000004;
    // long long rangeCost(long long left,long long right){
    //     long long leftSum=left%MOD * ((left-1)%MOD) %MOD * INV2 %MOD;
    //     long long rightSum=right% MOD *((right+1)%MOD) %MOD *INV2 %MOD;
    //     return (rightSum - leftSum + MOD) % MOD;
    // }
    // int minimumCost(vector<int>& nums, int k) {
    //     long long cost=0,curResource=k,lastCostMP=1;
    //     for(int x:nums){
    //         if(x<=curResource)  curResource-=x;
    //         else{
    //             int leftOut=x-curResource;
    //             int timesAdd=(leftOut+k-1)/k; //ceil
    //             //if we inc n times from init..we reach init+n
    //             //we need to calculate cost for (initMP,initMP+n-1)
    //             curResource=timesAdd*k-leftOut;
    //             cost=(0LL+cost+rangeCost(lastCostMP,lastCostMP+timesAdd-1))%MOD;
    //             lastCostMP=lastCostMP+timesAdd;
    //         }
    //     }
    //     return cost%MOD;
    // }
    int minimumCost(vector<int>& nums, int k) {
        long long sum=0;
        for(int x:nums)     sum+=x;
        sum-=k;
        if(sum<=0)    return 0;
        long long timesAdd=(sum+k-1)/k;
        long long cost=timesAdd % MOD * ((timesAdd+1)% MOD) % MOD *INV2 %MOD;
        return (int)cost;
    }
};