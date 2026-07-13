class Solution {
public:
    int minOperations(vector<int>& nums) {
        int keep=0,n=nums.size(),j=0;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        for(int i=0;i<n;i++){
            int lim=nums[i]+n-1;
            //int j=upper_bound(nums.begin(),nums.end(),lim)-nums.begin();
            while(j<nums.size() && nums[j]-nums[i]<n)  j++;
            keep=max(keep,j-i);
        }
        return n-keep;
    }
};