class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,minProd=1,maxProd=1;
        for(int x:nums){
            if(x<0) swap(minProd,maxProd);
            minProd=min(x,minProd*x);
            maxProd=max(x,maxProd*x);
            ans=max(ans,maxProd);
        }
        return ans;
    }
};