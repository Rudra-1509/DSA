class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<int> nums(m*n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums[i*n+j]=grid[i][j];
            }
        }
        sort(nums.begin(),nums.end());
        int target=nums[nums.size()/2];
        for(int num:nums){
            int diff=abs(num-target);
            if(diff%x>0)    return -1; 
            ans+=diff/x;  
        }
        return ans;
    }
};