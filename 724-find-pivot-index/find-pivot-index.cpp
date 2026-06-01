class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> preSum(n+1,0);
        for(int i=0;i<n;i++){
            preSum[i+1]=preSum[i]+nums[i];
        }
        int right=preSum[n],ans=-1;
        for(int i=n;i>0;i--){
            if(right-preSum[i]==preSum[i-1])
                ans=i-1;
        }
        return ans;
    }
};