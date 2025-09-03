class Solution {
public:
    bool helper(vector<int>& nums,int n,int target,vector<vector<bool>>& t){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(j==0)    t[i][j]=true;
                else if(i==0)   t[i][j]=false;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]= t[i-1][j]||t[i-1][j-nums[i-1]];
                }
                else    t[i][j]=t[i-1][j];
            }
        }
        return t[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)    return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<bool>> t(n+1,vector<bool>(target+1));
        return helper(nums,n,target,t);
    }
};