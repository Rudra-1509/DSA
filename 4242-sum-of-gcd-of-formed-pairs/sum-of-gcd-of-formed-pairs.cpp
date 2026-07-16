class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int& x:nums){
            maxi=max(maxi,x);
            x=gcd(x,maxi);
        }
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        long long sum=0;
        while(l<r)
            sum+=gcd(nums[l++],nums[r--]);
        return sum;
    }
};