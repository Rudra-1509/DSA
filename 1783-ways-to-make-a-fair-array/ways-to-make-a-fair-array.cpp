class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int leftOdd=0,leftEven=0,rightOdd=0,rightEven=0,n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            if(i & 1)
                rightOdd+=nums[i];
            else
                rightEven+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(i & 1)   rightOdd-=nums[i];
            else        rightEven-=nums[i];
            int newOdd=leftOdd+rightEven;
            int newEven=leftEven+rightOdd;
            if(newOdd==newEven)  ans++;
            if(i & 1)   leftOdd+=nums[i];
            else        leftEven+=nums[i];
        }
        return ans;
    }
};