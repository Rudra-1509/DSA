class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,minprod=1,maxprod=1;
        for(int x:nums){
            if(x<0) swap(minprod,maxprod);
            maxprod=max(x,maxprod*x);
            minprod=min(x,minprod*x);
            ans=max(maxprod,ans);
        }
        return ans;
    }
};